#include <cmath>
#include "gtest/gtest.h"
#include "math_utils/math_functions.h"
#include "random.h"

TEST(BernoulliDistribution, real_theory) {
  double p = 0.5;
  const int COUNT = 100000;
  cuhksz::BernoulliDistribution bernoulli(p);
  int bucket[2];
  for (int i = 0; i < 2; i++) bucket[i] = 0;
  for (int i = 0; i < COUNT; i++) {
    bucket[bernoulli.next()] += 1;
  }
  double error_sum = 0;
  for (int i = 0; i < 2; i++) {
    double real = double(bucket[i]) / COUNT;
    double theory;
    if (i == 0) {
      theory = p;
    } else {
      theory = 1 - p;
    }
    error_sum += std::abs(real - theory) / theory;
  }
  EXPECT_LT(error_sum / 2, 0.05);
}

TEST(BernoulliDistribution, construct) {
  cuhksz::BernoulliDistribution dist;
  cuhksz::BernoulliDistribution dist2(0.2);
  cuhksz::Random r(0);
  cuhksz::Random r2(0);
  cuhksz::BernoulliDistribution d1(r);
  cuhksz::BernoulliDistribution d2(r2, 0.5);
  EXPECT_EQ(d1.next(), d2.next());
}

TEST(BernoulliDistribution, p) {
  cuhksz::BernoulliDistribution dist;
  EXPECT_DOUBLE_EQ(dist.p(), 0.5);
}
