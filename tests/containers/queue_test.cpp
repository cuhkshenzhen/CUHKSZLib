#include "gtest/gtest.h"
#include "containers/Queue.h"
#include <queue>

cuhksz::Queue<int> testQueue;
std::queue<int> stlQueue;

TEST(queueTest, initialize) {
    stlQueue.push(1);
    cuhksz::Queue<int> initQueue1(stlQueue);
}

TEST(queueTest, typeConvert) {
    auto queue1 = testQueue.toStlQueue();
    std::queue<int> queue2 = testQueue;
    EXPECT_EQ(typeid(queue1), typeid(std::queue<int>));
    EXPECT_EQ(typeid(queue2), typeid(std::queue<int>));
}

TEST(queueTest, eqOperator) {
    cuhksz::Queue<int> initQueue1(stlQueue);
    testQueue = initQueue1;
    EXPECT_EQ(testQueue.size(), 1);
}

TEST(queueTest, enqueue) {
    testQueue.enqueue(1);
    testQueue.enqueue(2);
    testQueue.enqueue(3);
    EXPECT_EQ(testQueue.size(), 4);
}

TEST(queueTest, first) {
    EXPECT_EQ(testQueue.first(), 1);
}

TEST(queueTest, last) {
    EXPECT_EQ(testQueue.last(), 3);
}

TEST(queueTest, dequeue) {
    EXPECT_EQ(testQueue.dequeue(), 1);
    EXPECT_EQ(testQueue.dequeue(), 1);
    EXPECT_EQ(testQueue.first(), 2);
    EXPECT_EQ(testQueue.size(), 2);
}

TEST(queueTest, clear) {
    testQueue.clear();
    EXPECT_TRUE(testQueue.isEmpty());
}

TEST(queueDeathTest, emptyDeath) {
    EXPECT_DEATH(testQueue.dequeue(), "empty");
}
