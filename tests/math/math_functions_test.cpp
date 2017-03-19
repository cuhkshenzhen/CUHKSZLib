#include "math/math_functions.h"
#include <cmath>
#include "gtest/gtest.h"

TEST(MathFunctions, gcd) {
  EXPECT_EQ(cuhksz::gcd(10, 100), 10);
  EXPECT_EQ(cuhksz::gcd(20, 12), 4);
  EXPECT_EQ(cuhksz::gcd(17, 41), 1);
  EXPECT_EQ(cuhksz::gcd(10, 0), 10);
}

TEST(MathFunctions, lcm) {
  EXPECT_EQ(cuhksz::lcm(10, 100), 100);
  EXPECT_EQ(cuhksz::lcm(3, 5), 15);
}

TEST(MathFunctions, sum_int) {
  int sum[] = {1, 2, 4, 3};
  EXPECT_EQ(cuhksz::sum(sum, 4), 10);
}

TEST(MathFunctions, sum_double) {
  double sum[] = {1.2, 2, 4.2, 3.1};
  EXPECT_DOUBLE_EQ(cuhksz::sum(sum, 4), 10.5);
}

TEST(MathFunctions, mean) {
  double arr[] = {1, 2, 3};
  EXPECT_DOUBLE_EQ(cuhksz::mean(arr, 3), 2.0);
}

TEST(MathFunctions, stddev) {
  double arr[] = {1, 2, 3};
  EXPECT_DOUBLE_EQ(cuhksz::stddev(arr, 3), std::sqrt(2. / 3));
}

TEST(MathFunctions, pow) {
  EXPECT_EQ(cuhksz::pow(100, 0), 1);
  EXPECT_EQ(cuhksz::pow(2, 32), 4294967296);
  EXPECT_EQ(cuhksz::pow(2, 63), 9223372036854775808);
  EXPECT_EQ(cuhksz::pow(3, 27), 7625597484987);
}
