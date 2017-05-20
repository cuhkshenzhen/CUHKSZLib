#include <cmath>
#include "gtest/gtest.h"
#include "math_utils/math_functions.h"
#include "random/NegativeBinomialDistribution.h"

TEST(NegativeBinomialDistribution, real_theory) {
  int r = 5;
  double p = 0.5;
  const int COUNT = 100000;
  cuhksz::NegativeBinomialDistribution negbi(r, p);
  int bucket[11];
  for (int i = 0; i < 11; i++) bucket[i] = 0;
  for (int i = 0; i < COUNT; i++) {
    int rnd = negbi.next();
    if (rnd <= 10) bucket[rnd] += 1;
  }
  double error_sum = 0;
  double p_r = std::pow(p, r);
  for (int i = 0; i < 11; i++) {
    double real = double(bucket[i]) / COUNT;
    double theory =
        cuhksz::binomial(i + r - 1, r - 1) * p_r * std::pow(1 - p, i);
    error_sum += std::abs(real - theory) / theory;
  }
  EXPECT_LT(error_sum / 11, 0.05);
}

TEST(NegativeBinomialDistribution, construct) {
  cuhksz::NegativeBinomialDistribution dist(3);
  cuhksz::NegativeBinomialDistribution dist2(3, 0.2);
  cuhksz::Random r(0);
  cuhksz::Random r2(0);
  cuhksz::NegativeBinomialDistribution d1(r, 3);
  cuhksz::NegativeBinomialDistribution d2(r2, 3, 0.5);
  EXPECT_EQ(d1.next(), d2.next());
}

TEST(NegativeBinomialDistribution, r) {
  cuhksz::NegativeBinomialDistribution dist(2);
  EXPECT_EQ(dist.r(), 2);
}

TEST(NegativeBinomialDistribution, p) {
  cuhksz::NegativeBinomialDistribution dist(2);
  EXPECT_DOUBLE_EQ(dist.p(), 0.5);
}

TEST(NegativeBinomialDistributionDeathTest, parameter_invalid) {
  EXPECT_EXIT(cuhksz::NegativeBinomialDistribution(-1, 0.5),
              ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid");
  EXPECT_EXIT(cuhksz::NegativeBinomialDistribution(0, 0.5),
              ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid");
  EXPECT_EXIT(cuhksz::NegativeBinomialDistribution(1, 0),
              ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid");
  EXPECT_EXIT(cuhksz::NegativeBinomialDistribution(1, -1),
              ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid");
  EXPECT_EXIT(cuhksz::NegativeBinomialDistribution(1, 1.1),
              ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid");
}
