#include "math/math_functions.h"
#include <cmath>
#include "gtest/gtest.h"

TEST(MathFunctions, gcd) {
  ASSERT_EQ(cuhksz::gcd(10, 100), 10);
  ASSERT_EQ(cuhksz::gcd(20, 12), 4);
  ASSERT_EQ(cuhksz::gcd(17, 41), 1);
  ASSERT_EQ(cuhksz::gcd(10, 0), 10);
}

TEST(MathFunctions, lcm) {
  ASSERT_EQ(cuhksz::lcm(10, 100), 100);
  ASSERT_EQ(cuhksz::lcm(3, 5), 15);
}

TEST(MathFunctions, mean) {
  double arr[] = {1, 2, 3};
  ASSERT_EQ(cuhksz::mean(arr, 3), 2.0);
}

TEST(MathFunctions, stddev) {
  ASSERT_LT(cuhksz::stddev((const double[]){1, 2, 3}, 3) - std::sqrt(2. / 3),
            1e-14);
}
