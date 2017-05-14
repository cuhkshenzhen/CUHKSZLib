#include <cmath>
#include "gtest/gtest.h"
#include "math_utils/math_functions.h"
#include "random.h"

TEST(GammaDistribution, real_theory) {
  double k = 9.5;
  double theta = 1.0;
  const int COUNT = 100000;
  cuhksz::GammaDistribution gamma(k, theta);
  int bucket[11];
  for (int i = 0; i < 11; i++) bucket[i] = 0;
  for (int i = 0; i < COUNT; i++) {
    double rnd = gamma.next();
    if (rnd >= 0 && rnd < 11) {
      bucket[(int)rnd] += 1;
    }
  }
  double error_sum = 0;
  double theories[] = {3.58451e-7, 0.000105982, 0.0019652, 0.0112576,
                       0.0337251,  0.0673205,   0.101934,  0.126413,
                       0.13484,    0.12786,     0.110322};
  for (int i = 2; i < 11; i++) {
    double real = double(bucket[i]) / COUNT;
    double theory = theories[i];
    error_sum += std::abs(real - theory) / theory;
  }
  EXPECT_LT(error_sum / 9, 0.05);
}

TEST(GammaDistribution, construct) {
  cuhksz::GammaDistribution dist(2, 3);
  cuhksz::Random r(0);
  cuhksz::Random r2(0);
  cuhksz::GammaDistribution d1(r, 3, 3);
  cuhksz::GammaDistribution d2(r2, 3, 3);
  EXPECT_DOUBLE_EQ(d1.next(), d2.next());
}

TEST(GammaDistribution, k) {
  cuhksz::GammaDistribution dist(2, 4);
  EXPECT_DOUBLE_EQ(dist.k(), 2);
}

TEST(GammaDistribution, theta) {
  cuhksz::GammaDistribution dist(2, 4);
  EXPECT_DOUBLE_EQ(dist.theta(), 4);
}

TEST(GammaDistributionDeathTest, parameter_invalid) {
  EXPECT_EXIT(cuhksz::GammaDistribution(0, 0),
              ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid");
  EXPECT_EXIT(cuhksz::GammaDistribution(1, -1),
              ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid");
  EXPECT_EXIT(cuhksz::GammaDistribution(-1, 1),
              ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid");
  EXPECT_EXIT(cuhksz::GammaDistribution(-1, -1),
              ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid");
}
