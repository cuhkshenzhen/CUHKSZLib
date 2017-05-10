#include <cmath>
#include "gtest/gtest.h"
#include "math_utils/math_functions.h"
#include "random.h"

TEST(StudentTDistribution, real_theory) {
  double r = 1;
  const int COUNT = 100000;
  cuhksz::StudentTDistribution student(r);
  int bucket[11];
  for (int i = 0; i < 10; i++) bucket[i] = 0;
  for (int i = 0; i < COUNT; i++) {
    double rnd = student.next();
    if (rnd >= -5 && rnd < 6) {
      bucket[(int)std::floor(rnd) + 5] += 1;
    }
  }
  double error_sum = 0;
  double theories[] = {0.0151, 0.0244, 0.0452, 0.1024, 0.2500, 0.2500,
                       0.1024, 0.0452, 0.0244, 0.0151, 0.0103};
  for (int i = 0; i < 10; i++) {
    double real = double(bucket[i]) / COUNT;
    double theory = theories[i];
    error_sum += std::abs(real - theory) / theory;
  }
  EXPECT_LT(error_sum / 10, 0.05);
}

TEST(StudentTDistribution, construct) {
  cuhksz::StudentTDistribution dist(2);
  cuhksz::Random r(0);
  cuhksz::Random r2(0);
  cuhksz::StudentTDistribution d1(r, 0.5);
  cuhksz::StudentTDistribution d2(r2, 0.5);
  EXPECT_DOUBLE_EQ(d1.next(), d2.next());
}

TEST(StudentTDistribution, r) {
  cuhksz::StudentTDistribution dist(2.5);
  EXPECT_DOUBLE_EQ(dist.r(), 2.5);
}

TEST(StudentTDistributionDeathTest, parameter_invalid) {
  EXPECT_EXIT(cuhksz::StudentTDistribution(0),
              ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid");
  EXPECT_EXIT(cuhksz::StudentTDistribution(-1),
              ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid");
}
