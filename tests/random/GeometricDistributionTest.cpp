#include <cmath>
#include "gtest/gtest.h"
#include "math_utils/math_functions.h"
#include "random.h"

TEST(GeometricDistribution, real_theory) {
  double p = 0.5;
  const int COUNT = 100000;
  cuhksz::GeometricDistribution geodist(p);
  int bucket[5];
  for (int i = 0; i < 5; i++) bucket[i] = 0;
  for (int i = 0; i < COUNT; i++) {
    int rnd = geodist.next();
    if (rnd < 5) bucket[rnd] += 1;
  }
  double error_sum = 0;
  for (int i = 0; i < 5; i++) {
    double real = double(bucket[i]) / COUNT;
    double theory = p * std::pow(1 - p, i);
    error_sum += std::abs(real - theory) / theory;
  }
  EXPECT_LT(error_sum / 5, 0.05);
}

TEST(GeometricDistribution, construct) {
  cuhksz::GeometricDistribution dist;
  cuhksz::GeometricDistribution dist2(0.2);
  cuhksz::Random r(0);
  cuhksz::Random r2(0);
  cuhksz::GeometricDistribution d1(r);
  cuhksz::GeometricDistribution d2(r2, 0.5);
  EXPECT_EQ(d1.next(), d2.next());
}

TEST(GeometricDistribution, p) {
  cuhksz::GeometricDistribution dist;
  EXPECT_DOUBLE_EQ(dist.p(), 0.5);
}
