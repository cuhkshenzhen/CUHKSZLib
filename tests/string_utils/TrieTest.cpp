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
