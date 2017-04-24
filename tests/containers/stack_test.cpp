#include "gtest/gtest.h"
#include "containers/Stack.h"

cuhksz::Stack<int> testStack;

TEST(stackTest, push) {
    testStack.push(1);
    testStack.push(2);
    testStack.push(3);
    EXPECT_EQ(testStack.size(), 3);
}

TEST(stackTest, pop) {
    EXPECT_EQ(testStack.pop(), 3);
}

TEST(stackTest, top) {
    EXPECT_EQ(testStack.top(), 2);
}

TEST(stackTest, clear) {
    testStack.clear();
    EXPECT_TRUE(testStack.isEmpty());
}

TEST(stackDeathTest, emptyPopDeath) {
    EXPECT_DEATH(testStack.pop(), "");
}

// TEST(forDeathTest, rangeForLoop) {
// 	EXPECT_EXIT(
// 		for (auto x:testStack) {continue;},
// 		testing::ExitedWithCode(0),
// 		""
// 		);
// }
