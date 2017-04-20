#include "gtest/gtest.h"
#include "containers/Vector.h"

cuhksz::Vector<int> testVector;

TEST(vectorTest, push) {
    testVector.push(1);
    testVector.push(2);
    testVector.push(3);
    EXPECT_EQ(testVector.size(), 3);
}

TEST(vectorTest, erase) {
    testVector.erase(0);
    EXPECT_EQ(testVector[0], 2);
}

TEST(vectorTest, insert) {
    testVector.insert(0, 1);
    EXPECT_EQ(testVector[0], 1);
    EXPECT_EQ(testVector.size(), 3);

    testVector.insert(2, 4);
    EXPECT_EQ(testVector[2], 4);
    EXPECT_EQ(testVector.size(), 4);
}

TEST(vectorTest, set) {
    testVector.set(2, 5);
    EXPECT_EQ(testVector[2], 5);
}

TEST(vectorTest, clear) {
    testVector.clear();
    EXPECT_TRUE(testVector.isEmpty());
}

TEST(forDeathTest, rangeForLoop) {
	EXPECT_EXIT(
		for (auto x:testVector) {continue;},
		testing::ExitedWithCode(0), 
		""	
		);
}



