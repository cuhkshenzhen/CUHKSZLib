#include "algorithm.h"
#include "gtest/gtest.h"

TEST(Algorithm, kmpSearch) {
  EXPECT_EQ(cuhksz::kmpSearch("abc", "abc"), 0);
  EXPECT_EQ(cuhksz::kmpSearch("abc", "abc", 1), -1);
  EXPECT_EQ(cuhksz::kmpSearch("abcabced", "abc", 1), 3);
  EXPECT_EQ(cuhksz::kmpSearch("sdeczse", "abc"), -1);
  EXPECT_EQ(cuhksz::kmpSearch("abdecabc", "abc"), 5);
}
