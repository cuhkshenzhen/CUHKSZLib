#include <iostream>
#include <list>
#include "containers/List.h"
#include "gtest/gtest.h"

cuhksz::List<int> testList;
std::list<int> testStlList = {1, 2, 3, 4};

TEST(listTest, initialize) {
  cuhksz::List<int> initList1(5, 1);
  EXPECT_EQ(initList1.size(), 5);
  cuhksz::List<int> initList2 = {1, 2, 1};
  EXPECT_EQ(initList2.size(), 3);
  cuhksz::List<int> initList3(testStlList);
  EXPECT_EQ(initList3.size(), 4);
}

TEST(listTest, typeConvert) {
  auto list1 = testList.toStlList();
  std::list<int> list2 = testList;
  EXPECT_EQ(list1, list2);
}

TEST(listTest, eqOperator) {
  cuhksz::List<int> initList1(5, 1);
  testList = initList1;
  EXPECT_EQ(testList.size(), 5);
}

TEST(listTest, first) {
  testList.first() = 10;
  EXPECT_EQ(testList.first(), 10);
}

TEST(listTest, last) {
  testList.last() = 9;
  EXPECT_EQ(testList.last(), 9);
}

TEST(listTest, indexOperator) {
  testList[1] = 8;
  EXPECT_EQ(testList[1], 8);
}

TEST(listTest, push) {
  testList.push(1);
  testList.push(2);
  testList.push(3);
  EXPECT_EQ(testList.size(), 8);
  EXPECT_EQ(testList.last(), 3);
}

TEST(listTest, push_front) {
  testList.push_front(5);
  EXPECT_EQ(testList.first(), 5);
  EXPECT_EQ(testList.size(), 9);
}

TEST(listTest, insert) {
  testList.insert(0, 1);
  EXPECT_EQ(testList[0], 1);

  testList.insert(2, 4);
  EXPECT_EQ(testList[2], 4);

  EXPECT_EQ(testList.size(), 11);
}

TEST(listTest, erase) {
  testList.erase(2);
  EXPECT_EQ(testList.size(), 10);
}

TEST(listTest, pop) {
  EXPECT_EQ(testList.pop(), 3);
  EXPECT_EQ(testList.size(), 9);
}

TEST(listTest, pop_front) {
  EXPECT_EQ(testList.pop_front(), 1);
  EXPECT_EQ(testList.size(), 8);
}

TEST(listTest, clear) {
  testList.clear();
  EXPECT_TRUE(testList.isEmpty());
}

// following are death tests
TEST(listDeathTest, outrangeDeath) {
  EXPECT_DEATH(testList[8] = 1, "range");
  EXPECT_DEATH(testList.erase(8), "range");
  EXPECT_DEATH(testList.insert(4, 1), "range");
}

TEST(listDeathTest, emptyDeath) {
  EXPECT_DEATH(testList.pop(), "empty");
  EXPECT_DEATH(testList.pop_front(), "empty");
  EXPECT_DEATH(testList.first(), "empty");
  EXPECT_DEATH(testList.last(), "empty");
}
