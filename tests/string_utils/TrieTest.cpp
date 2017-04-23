#include "gtest/gtest.h"
#include "string_utils/Trie.h"

#include <string>
#include <vector>

TEST(Trie, insert_and_contain) {
  cuhksz::Trie trie;
  std::vector<std::string> strs = {"ba", "bac", "be", "bae"};
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
}
