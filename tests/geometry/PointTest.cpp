#include "geometry/Point.h"

#include "gtest/gtest.h"

TEST(Point, initialize) {
    cuhksz::Point<1> a1, b1(5);
    EXPECT_DOUBLE_EQ(b1[0], 5);

    cuhksz::Point<2> a2, b2(2, 3);
    EXPECT_DOUBLE_EQ(b2[0], 2);
    EXPECT_DOUBLE_EQ(b2[1], 3);

    cuhksz::Point<3> a3, b3(1, 2, 3);
    EXPECT_DOUBLE_EQ(b3[0], 1);
    EXPECT_DOUBLE_EQ(b3[1], 2);
    EXPECT_DOUBLE_EQ(b3[2], 3);
}

TEST(GVector, addition) {
    cuhksz::GVector<2> a(2, 3), b(1, 5), c;
    c = a + b;
    EXPECT_DOUBLE_EQ(c[0], 3);
    EXPECT_DOUBLE_EQ(c[1], 8);
}

TEST(GVector, subtraction) {
    cuhksz::GVector<2> a(2, 3), b(1, 5), c;
    c = a - b;
    EXPECT_DOUBLE_EQ(c[0], 1);
    EXPECT_DOUBLE_EQ(c[1], -2);
}

TEST(GVector, mulNumber) {
    cuhksz::GVector<2> a(2, 3), b;
    b = a * 2;
    EXPECT_DOUBLE_EQ(b[0], 4);
    EXPECT_DOUBLE_EQ(b[1], 6);
    a = 2 * b;
    EXPECT_DOUBLE_EQ(a[0], 8);
    EXPECT_DOUBLE_EQ(a[1], 12);
}

TEST(GVector, dotProduct) {
    cuhksz::GVector<2> a(2, 3), b(3, 5);
    EXPECT_DOUBLE_EQ(dot(a, b), 21);

    a = cuhksz::GVector<2>(-2, 3);
    b = cuhksz::GVector<2>(1, -5);
    EXPECT_DOUBLE_EQ(a * b, -17);
}

TEST(GVector, crossProduct) {
    cuhksz::Point<2> a(2, 3), b(3, 5);
    EXPECT_DOUBLE_EQ(cross(a, b), 1);
}

TEST(GVector, len) {
    cuhksz::GVector<2> a(3, 4);
    EXPECT_DOUBLE_EQ(a.len(), 5);
}
