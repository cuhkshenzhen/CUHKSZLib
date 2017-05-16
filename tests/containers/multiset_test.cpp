#include "containers/MultiSet.h"
#include "gtest/gtest.h"

#include <set>

cuhksz::MultiSet<int> testMultiSet;
std::multiset<int> stlMultiSet = {1, 1, 2, 2, 3, 3};

TEST(multisetTest, initialize) {
  cuhksz::MultiSet<int> initMultiSet1{1, 2, 4, 1, 2, 3};
  EXPECT_EQ(initMultiSet1.size(), 6);
  cuhksz::MultiSet<int> initMultiSet2(stlMultiSet);
  EXPECT_EQ(initMultiSet2.size(), 6);
}

TEST(multisetTest, typeConvert) {
  auto multiset1 = testMultiSet.toStlMultiset();
  std::multiset<int> multiset2 = testMultiSet;
  EXPECT_EQ(multiset1, multiset2);
}

TEST(multisetTest, eqOperator) {
  cuhksz::MultiSet<int> initMultiSet1{1, 2, 4, 1, 2, 3};
  testMultiSet = initMultiSet1;
  EXPECT_EQ(testMultiSet.size(), 6);
}

TEST(multisetTest, insert) {
  testMultiSet.insert(1);
  EXPECT_EQ(testMultiSet.size(), 7);
}

TEST(multisetTest, erase) {
  testMultiSet.erase(4);
  EXPECT_EQ(testMultiSet.size(), 6);
}

TEST(multisetTest, count) {
  EXPECT_EQ(testMultiSet.count(1), 3);
  EXPECT_EQ(testMultiSet.count(3), 1);
  EXPECT_EQ(testMultiSet.count(9), 0);
}

TEST(multisetTest, contains) {
  EXPECT_TRUE(testMultiSet.contains(3));
  EXPECT_FALSE(testMultiSet.contains(10));
}

TEST(multisetTest, clear) {
  testMultiSet.clear();
  EXPECT_TRUE(testMultiSet.isEmpty());
}

TEST(multisetTest, eraseDeath) {
  EXPECT_DEATH(testMultiSet.erase(12), "value");
}
