#include <cmath>
#include "gtest/gtest.h"
#include "math_utils/math_functions.h"
#include "random/ExponentialDistribution.h"

TEST(ExponentialDistribution, real_theory) {
  double lambda = 0.5;
  const int COUNT = 100000;
  cuhksz::ExponentialDistribution exponential(lambda);
  int bucket[6];
  for (int i = 0; i < 6; i++) bucket[i] = 0;
  for (int i = 0; i < COUNT; i++) {
    double rnd = exponential.next();
    if (rnd >= 0 && rnd < 6) {
      bucket[(int)rnd] += 1;
    }
  }
  double error_sum = 0;
  for (int i = 0; i < 6; i++) {
    double real = double(bucket[i]) / COUNT;
    double theory = std::exp(-lambda * i) - std::exp(-lambda * (i + 1));
    error_sum += std::abs(real - theory) / theory;
  }
  EXPECT_LT(error_sum / 6, 0.05);
}

TEST(ExponentialDistribution, construct) {
  cuhksz::ExponentialDistribution dist(2);
  cuhksz::Random r(0);
  cuhksz::Random r2(0);
  cuhksz::ExponentialDistribution d1(r, 2);
  cuhksz::ExponentialDistribution d2(r2, 2);
  EXPECT_DOUBLE_EQ(d1.next(), d2.next());
}

TEST(ExponentialDistribution, lambda) {
  cuhksz::ExponentialDistribution dist(2);
  EXPECT_DOUBLE_EQ(dist.lambda(), 2);
}
