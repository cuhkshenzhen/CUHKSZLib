#include <iostream>
#include <sstream>
#include <vector>
#include "containers/Vector.h"
#include "gtest/gtest.h"
#include "utils/error.h"

cuhksz::Vector<int> testVector;
std::vector<int> stlVector = {1, 2, 3, 4};

TEST(vectorTest, initialize) {
  cuhksz::Vector<int> initVector1(5, 1);
  EXPECT_EQ(initVector1.size(), 5);
  cuhksz::Vector<int> initVector2 = {1, 2, 1};
  EXPECT_EQ(initVector2.size(), 3);
  cuhksz::Vector<int> initVector3(stlVector);
  EXPECT_EQ(initVector3.size(), 4);
}

TEST(vectorTest, typeConvert) {
  auto vector1 = testVector.toStlVector();
  std::vector<int> vector2 = testVector;
  EXPECT_EQ(vector1, vector2);
}

TEST(vectorTest, eqOperator) {
  cuhksz::Vector<int> initVector1(5, 1);
  testVector = initVector1;
  EXPECT_EQ(testVector.size(), 5);
}

TEST(vectorTest, get) { EXPECT_EQ(testVector.get(1), 1); }

TEST(vectorTest, indexOperator) { EXPECT_EQ(testVector[1], 1); }

TEST(vectorTest, push) {
  testVector.push(1);
  testVector.push(2);
  testVector.push(3);
  EXPECT_EQ(testVector.size(), 8);
}

TEST(vectorTest, erase) {
  testVector.erase(5);
  EXPECT_EQ(testVector[5], 2);
  EXPECT_EQ(testVector.size(), 7);
}

TEST(vectorTest, insert) {
  testVector.insert(2, 4);
  EXPECT_EQ(testVector[2], 4);
  EXPECT_EQ(testVector.size(), 8);
}

TEST(vectorTest, set) {
  testVector.set(2, 5);
  EXPECT_EQ(testVector[2], 5);
  EXPECT_EQ(testVector.size(), 8);
}

TEST(vectorTest, pop) {
  EXPECT_EQ(testVector.pop(), 3);
  EXPECT_EQ(testVector.size(), 7);
}

TEST(vectorTest, clear) {
  testVector.clear();
  EXPECT_TRUE(testVector.isEmpty());
}

TEST(vectorDeathTest, rangeDeath) {
  EXPECT_DEATH(testVector.get(9), "range");
  EXPECT_DEATH(testVector[10], "range");
  EXPECT_DEATH(testVector.erase(8), "range");
  EXPECT_DEATH(testVector.set(12, 1), "range");
}

TEST(vectorDeathTest, emptyDeath) { EXPECT_DEATH(testVector.pop(), "empty"); }

TEST(vectorTest, istreamOperator) {
  std::istringstream inputVector("{1, 2, 3, 5, 6, 7, 8}");
  inputVector >> testVector;
  EXPECT_EQ(testVector.size(), 7);
}

TEST(vectorTest, ostreamOperator) {
  std::stringstream outVector;
  outVector << testVector;
  EXPECT_EQ(outVector.str(), "{1, 2, 3, 5, 6, 7, 8}");
}

TEST(vectorDeathTest, istreamDeathTest) {
  cuhksz::Vector<int> inputTestVector;
  std::istringstream inputVector1("1, 2, 3");
  std::istringstream inputVector2("{1, 2, 3");
  std::istringstream inputVector3("{1, 2? 3}");
  EXPECT_DEATH(inputVector1 >> inputTestVector, "startwith '\\{'");
  EXPECT_DEATH(inputVector2 >> inputTestVector, "endwith");
  EXPECT_DEATH(inputVector3 >> inputTestVector, "Unexpected character");
}
