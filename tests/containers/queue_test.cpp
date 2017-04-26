#include "gtest/gtest.h"
#include "containers/Queue.h"

cuhksz::Queue<int> testQueue;

TEST(queueTest, enqueue) {
    testQueue.enqueue(1);
    testQueue.enqueue(2);
    testQueue.enqueue(3);
    EXPECT_EQ(testQueue.size(), 3);
}

TEST(queueTest, first) {
    EXPECT_EQ(testQueue.first(), 1);
}

TEST(queueTest, last) {
    EXPECT_EQ(testQueue.last(), 3);
}

TEST(queueTest, dequeue) {
    EXPECT_EQ(testQueue.dequeue(), 1);
    EXPECT_EQ(testQueue.first(), 2);
}

TEST(queueTest, clear) {
    testQueue.clear();
    EXPECT_TRUE(testQueue.isEmpty());
}

TEST(queueDeathTest, emptyPopDeath) {
    EXPECT_DEATH(testQueue.dequeue(), "");
}
