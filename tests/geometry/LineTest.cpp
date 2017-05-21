#include "geometry/Line.h"

#include "gtest/gtest.h"

TEST(Line, initialize) {
  cuhksz::Line a(cuhksz::Point<2>(0, 0), cuhksz::GVector<2>(2, 3));
  cuhksz::Line b(a);
}

TEST(Line, getIntersection) {
  cuhksz::Line a(cuhksz::Point<2>(0, 0), cuhksz::GVector<2>(1, 1));
  cuhksz::Line b(cuhksz::Point<2>(2, 0), cuhksz::GVector<2>(-1, 1));
  EXPECT_EQ(getIntersection(a, b), cuhksz::Point<2>(1, 1));
}

TEST(Line, disToLine) {
  cuhksz::Line a(cuhksz::Point<2>(0, 0), cuhksz::GVector<2>(1, 1));
  cuhksz::Point<2> b(2, 0);
  EXPECT_DOUBLE_EQ(disToLine(b, a), std::sqrt(2));
}

TEST(Line, disToSegment) {
  cuhksz::Line a(cuhksz::Point<2>(0, 0), cuhksz::GVector<2>(-1, -1));
  cuhksz::Point<2> b(2, 0);
  EXPECT_DOUBLE_EQ(disToSegment(b, a), 2);
}
