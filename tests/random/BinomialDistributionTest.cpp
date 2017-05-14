#include <cmath>
#include "gtest/gtest.h"
#include "math_utils/math_functions.h"
#include "random.h"

TEST(BinomialDistribution, real_theory) {
  double p = 0.5;
  double p_complement = 1.0 - p;
  int n = 10;
  const int COUNT = 100000;
  cuhksz::BinomialDistribution binodist(n, p);
  int bucket[11];
  for (int i = 0; i < 11; i++) bucket[i] = 0;
  for (int i = 0; i < COUNT; i++) {
    bucket[binodist.next()] += 1;
  }
  double error_sum = 0;
  for (int i = 0; i < 11; i++) {
    double real = double(bucket[i]) / COUNT;
    double theory =
        cuhksz::binomial(n, i) * std::pow(p, i) * std::pow(p_complement, n - i);
    error_sum += std::abs(real - theory) / theory;
  }
  EXPECT_LT(error_sum / 11, 0.06);
}

TEST(BinomialDistribution, construct) {
  cuhksz::BinomialDistribution dist(1);
  cuhksz::BinomialDistribution dist2(1, 0.2);
  cuhksz::Random r(0);
  cuhksz::Random r2(0);
  cuhksz::BinomialDistribution d1(r, 1);
  cuhksz::BinomialDistribution d2(r2, 1, 0.5);
  EXPECT_EQ(d1.next(), d2.next());
}

TEST(BinomialDistribution, p) {
  cuhksz::BinomialDistribution dist(1);
  EXPECT_DOUBLE_EQ(dist.p(), 0.5);
}

TEST(BinomialDistribution, n) {
  cuhksz::BinomialDistribution dist(3);
  EXPECT_EQ(dist.n(), 3);
}

TEST(BinomialDistributionDeathTest, parameter_invalid) {
  EXPECT_EXIT(cuhksz::BinomialDistribution(-1, 0.5),
              ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid");
  EXPECT_EXIT(cuhksz::BinomialDistribution(1, -1),
              ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid");
  EXPECT_EXIT(cuhksz::BinomialDistribution(0, 1.1),
              ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid");
}
