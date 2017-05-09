#include <cmath>
#include "gtest/gtest.h"
#include "math_utils/math_functions.h"
#include "random.h"

TEST(PoissonDistribution, real_theory) {
  double lambda = 5;
  const int COUNT = 100000;
  cuhksz::PoissonDistribution poisson(lambda);
  int bucket[11];
  for (int i = 0; i < 11; i++) bucket[i] = 0;
  for (int i = 0; i < COUNT; i++) {
    int rnd = poisson.next();
    if (rnd <= 10) bucket[rnd] += 1;
  }
  double error_sum = 0;
  double e_lambda = std::exp(-lambda);
  for (int i = 0; i < 11; i++) {
    double real = double(bucket[i]) / COUNT;
    double theory = e_lambda * std::pow(lambda, i) / cuhksz::factorial(i);
    error_sum += std::abs(real - theory) / theory;
  }
  EXPECT_LT(error_sum / 11, 0.05);
}

TEST(PoissonDistribution, construct) {
  cuhksz::PoissonDistribution dist(2);
  cuhksz::Random r(0);
  cuhksz::Random r2(0);
  cuhksz::PoissonDistribution d1(r, 3.5);
  cuhksz::PoissonDistribution d2(r2, 3.5);
  EXPECT_EQ(d1.next(), d2.next());
}

TEST(PoissonDistribution, lambda) {
  cuhksz::PoissonDistribution dist(1);
  EXPECT_DOUBLE_EQ(dist.lambda(), 1);
}
