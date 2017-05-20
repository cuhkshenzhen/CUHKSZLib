#include <cmath>
#include "gtest/gtest.h"
#include "math_utils/math_functions.h"
#include "random/NormalDistribution.h"

TEST(NormalDistribution, real_theory) {
  double mean = 6;
  double stddev = 5;
  const int COUNT = 100000;
  cuhksz::NormalDistribution normal(mean, stddev);
  int bucket[11];
  for (int i = 0; i < 11; i++) bucket[i] = 0;
  for (int i = 0; i < COUNT; i++) {
    double rnd = normal.next();
    if (rnd >= 0 && rnd < 11) {
      bucket[(int)rnd] += 1;
    }
  }
  double error_sum = 0;
  for (int i = 0; i < 11; i++) {
    double real = double(bucket[i]) / COUNT;
    double theory = 0.5 * (std::erf((i + 1 - mean) / stddev / std::sqrt(2)) -
                           std::erf((i - mean) / stddev / std::sqrt(2)));
    error_sum += std::abs(real - theory) / theory;
  }
  EXPECT_LT(error_sum / 11, 0.05);
}

TEST(NormalDistribution, construct) {
  cuhksz::NormalDistribution dist;
  cuhksz::NormalDistribution dist2(1);
  cuhksz::NormalDistribution dist3(1, 3);
  cuhksz::Random r(0);
  cuhksz::Random r2(0);
  cuhksz::NormalDistribution d1(r);
  cuhksz::NormalDistribution d2(r2, 0, 1);
  EXPECT_DOUBLE_EQ(d1.next(), d2.next());
}

TEST(NormalDistribution, mean) {
  cuhksz::NormalDistribution dist;
  EXPECT_DOUBLE_EQ(dist.mean(), 0);
}

TEST(NormalDistribution, stddev) {
  cuhksz::NormalDistribution dist;
  EXPECT_DOUBLE_EQ(dist.stddev(), 1);
}

TEST(NormalDistributionDeathTest, parameter_invalid) {
  EXPECT_EXIT(cuhksz::NormalDistribution(0, 0),
              ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid");
  EXPECT_EXIT(cuhksz::NormalDistribution(0, -1),
              ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid");
}
