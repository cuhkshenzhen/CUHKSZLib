#include "containers/Set.h"
#include "gtest/gtest.h"

#include <set>

cuhksz::Set<int> testSet;
std::set<int> stlSet;

TEST(setTest, initialize) {
  cuhksz::Set<int> initSet1 = {1, 2, 3};
  EXPECT_EQ(initSet1.size(), 3);
  cuhksz::Set<int> initSet2(stlSet);
  EXPECT_EQ(initSet2.size(), 0);
}

TEST(setTest, typeConvert) {
  auto set1 = testSet.toStlSet();
  std::set<int> set2 = testSet;
  EXPECT_EQ(set1, set2);
}

TEST(setTest, eqOperator) {
  cuhksz::Set<int> initSet1 = {1, 2, 3};
  testSet = initSet1;
  EXPECT_EQ(testSet.size(), 3);
}

TEST(setTest, insert) {
  testSet.insert(4);
  EXPECT_EQ(testSet.size(), 4);
}

TEST(setTest, erase) {
  testSet.erase(2);
  EXPECT_EQ(testSet.size(), 3);
}

TEST(setTest, contains) {
  EXPECT_TRUE(testSet.contains(1));
  EXPECT_FALSE(testSet.contains(9));
}

TEST(setTest, clear) {
  testSet.clear();
  EXPECT_TRUE(testSet.isEmpty());
}
