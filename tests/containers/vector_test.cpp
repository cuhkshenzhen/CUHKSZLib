#include "gtest/gtest.h"
#include "containers/Vector.h"

TEST(vector, vectorTest) {
    cuhksz::Vector<int> testVector;
    testVector.push(1);
    testVector.push(2);
    testVector.push(3);
    EXPECT_EQ(testVector.size(), 3);

    testVector.erase(0);
    EXPECT_EQ(testVector[0], 2);

    testVector.insert(0, 1);
    EXPECT_EQ(testVector[0], 1);
    EXPECT_EQ(testVector.size(), 3);

    testVector.insert(2, 4);
    EXPECT_EQ(testVector[2], 4);
    EXPECT_EQ(testVector.size(), 4);

    testVector.set(2, 5);
    EXPECT_EQ(testVector[2], 5);

    testVector.clear();
    EXPECT_TRUE(testVector.isEmpty());

    //to be added range-based for loop

}
