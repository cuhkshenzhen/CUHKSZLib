#include "geometry/Circle.h"

#include "gtest/gtest.h"

TEST(Circle, initialize) {
  cuhksz::Circle a, b(2), c(cuhksz::Point<2>(2, 3));
  cuhksz::Circle d(cuhksz::Point<2>(2, 3), 2);
}

TEST(Circle, getArea) {
  cuhksz::Circle a(cuhksz::Point<2>(2, 3), 2);
  EXPECT_DOUBLE_EQ(a.getArea(), 3.1415926 * 4);
}

TEST(Circle, getPerimeter) {
  cuhksz::Circle a(cuhksz::Point<2>(2, 3), 3);
  EXPECT_DOUBLE_EQ(a.getPerimeter(), 3.1415926 * 6);
}

TEST(Circle, getPoint) {
  cuhksz::Circle a(2);
  EXPECT_EQ(a.getPoint(3.1415926 / 4),
            cuhksz::Point<2>(std::sqrt(2), std::sqrt(2)));
}
