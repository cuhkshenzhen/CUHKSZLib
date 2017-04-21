#include "gtest/gtest.h"
#include "containers/List.h"

cuhksz::List<int> testList;

TEST(listTest, push) {
    testList.push(1);
    testList.push(2);
    testList.push(3);
    EXPECT_EQ(testList.size(), 3);
}

TEST(listTest, push_front) {
    testList.push_front(5);
    EXPECT_EQ(testList.first(), 5);
}

TEST(listTest, insert) {
    testList.insert(0, 1);
    EXPECT_EQ(testList[0], 1);
    EXPECT_EQ(testList.size(), 5);

    testList.insert(2, 4);
    EXPECT_EQ(testList[2], 4);
    EXPECT_EQ(testList.size(), 6);
}

TEST(listTest, erase) {
    testList.erase(2);
    EXPECT_EQ(testList.size(), 5);
}

TEST(listTest, pop) {
    EXPECT_EQ(testList.pop(), 3);
}

TEST(listTest, clear) {
    testList.clear();
    EXPECT_TRUE(testList.isEmpty());
}

TEST(rangeDeathTest, outrangeDeath) {
    EXPECT_DEATH(testList[8] = 1, "");
}

TEST(popDeathTest, emptypopDeath) {
    EXPECT_DEATH(testList.pop(), "");
}

// TEST(forDeathTest, rangeForLoop) {
// 	EXPECT_EXIT(
// 		for (auto x:testList) {continue;},
// 		testing::ExitedWithCode(0),
// 		""
// 		);
// }
