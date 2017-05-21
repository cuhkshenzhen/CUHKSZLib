#include <string>
#include <vector>

#include "string_utils/Trie.h"

#include "gtest/gtest.h"

int mapChar(char ch) {
  if (ch == '\001') return 1;
  if (ch < 'A' || ch > 'Z') exit(0);
  return ch - 'A' + 2;
}
char mapInt(int n) {
  if (n == 1) return '\001';
  return n - 2 + 'A';
}

TEST(Trie, custom_mapper) {
  cuhksz::Trie trie(mapChar, mapInt);
  trie.insert("ABC");
  EXPECT_TRUE(trie.contain("ABC"));
  for (auto str : trie) {
    EXPECT_EQ(str, "ABC");
  }
}

TEST(Trie, insert_and_contain) {
  cuhksz::Trie trie;
  std::vector<std::string> strs = {"ba", "bac", "be", "bae", "cea", "ce"};
  for (auto& s : strs) {
    trie.insert(s);
  }
  for (auto& s : strs) {
    EXPECT_TRUE(trie.contain(s));
  }
}

TEST(Trie, remove) {
  cuhksz::Trie trie;
  std::vector<std::string> strs = {"ba", "bac", "be", "bae"};
  for (auto& s : strs) {
    trie.insert(s);
  }
  trie.remove("be");
  EXPECT_FALSE(trie.contain("be"));
  for (auto& s : strs) {
    if (s != "be") EXPECT_TRUE(trie.contain(s));
  }
}

TEST(Trie, travel) {
  cuhksz::Trie trie;
  std::vector<std::string> strs = {"ba", "bac", "bae", "be"};
  for (auto& s : strs) {
    trie.insert(s);
  }
  int i = 0;
  for (auto s : trie) {
    EXPECT_EQ(s, strs[i]);
    i++;
  }
}

TEST(Trie, iterator) {
  cuhksz::Trie trie;
  std::vector<std::string> strs = {"ba", "bac", "bae", "be"};
  for (auto& s : strs) {
    trie.insert(s);
  }
  auto it = trie.begin();
  auto it2 = it;
  ++it;
  EXPECT_NE(it, it2);
}

TEST(Trie, size) {
  cuhksz::Trie trie;
  EXPECT_EQ(trie.size(), 0);
  trie.insert("abc");
  EXPECT_EQ(trie.size(), 1);
  trie.insert("abc");
  EXPECT_EQ(trie.size(), 1);
  trie.insert("bca");
  EXPECT_EQ(trie.size(), 2);
  trie.remove("abc");
  EXPECT_EQ(trie.size(), 1);
  trie.remove("aaa");
  EXPECT_EQ(trie.size(), 1);
  trie.remove("bca");
  EXPECT_EQ(trie.size(), 0);
  trie.insert("a");
  trie.insert("abc");
  trie.remove("abe");
  trie.remove("a");
  EXPECT_EQ(trie.size(), 1);
}

TEST(TrieDeathTest, unsupport_characters) {
  cuhksz::Trie trie;
  EXPECT_EXIT(trie.insert("Abc"), ::testing::ExitedWithCode(EXIT_FAILURE),
              "lower letter");
  trie.insert("bcA");  // good because it enters the `tail` array
  EXPECT_EXIT(trie.insert("bcAc"), ::testing::ExitedWithCode(EXIT_FAILURE),
              "lower letter");
}
