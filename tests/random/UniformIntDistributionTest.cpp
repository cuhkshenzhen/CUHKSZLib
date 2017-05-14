#include "gtest/gtest.h"
#include "math_utils/math_functions.h"
#include "random.h"

TEST(UniformIntDistribution, stddev) {
  cuhksz::UniformIntDistribution ud(100);
  int bucket[100];
  for (int i = 0; i < 100; i++) bucket[i] = 0;
  for (int i = 0; i < 100000; i++) {
    bucket[ud.next()] += 1;
  }
  EXPECT_LT(cuhksz::stddev(bucket, 100) / cuhksz::mean(bucket, 100), 0.05);
}

TEST(UniformIntDistribution, construct) {
  cuhksz::UniformIntDistribution dist(10);
  cuhksz::UniformIntDistribution dist2(5, 10);
  cuhksz::Random r(0);
  cuhksz::Random r2(0);
  cuhksz::UniformIntDistribution d1(r, 10);
  cuhksz::UniformIntDistribution d2(r2, 0, 10);
  EXPECT_EQ(d1.next(), d2.next());
}

TEST(UniformIntDistribution, min) {
  cuhksz::UniformIntDistribution dist(100);
  EXPECT_EQ(dist.min(), 0);
  cuhksz::UniformIntDistribution dist2(2, 3);
  EXPECT_EQ(dist2.min(), 2);
}

TEST(UniformIntDistribution, max) {
  cuhksz::UniformIntDistribution dist(100);
  EXPECT_EQ(dist.max(), 100);
  cuhksz::UniformIntDistribution dist2(2, 3);
  EXPECT_EQ(dist2.max(), 3);
}

TEST(UniformIntDistributionDeathTest, parameter_invalid) {
  EXPECT_EXIT(cuhksz::UniformIntDistribution(0, -1),
              ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid");
  EXPECT_EXIT(cuhksz::UniformIntDistribution(0, 0),
              ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid");
}
