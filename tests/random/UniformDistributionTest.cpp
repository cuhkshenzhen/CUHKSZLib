#include "gtest/gtest.h"
#include "math_utils/math_functions.h"
#include "random.h"

TEST(UniformDistribution, stddev) {
  cuhksz::UniformDistribution ud(100);
  int bucket[100];
  for (int i = 0; i < 100; i++) bucket[i] = 0;
  for (int i = 0; i < 100000; i++) {
    bucket[(int)ud.next()] += 1;
  }
  EXPECT_LT(cuhksz::stddev(bucket, 100) / cuhksz::mean(bucket, 100), 0.05);
}

TEST(UniformDistribution, construct) {
  cuhksz::UniformDistribution dist;
  cuhksz::UniformDistribution dist2(0.2);
  cuhksz::UniformDistribution dist3(0.2, 1);
  cuhksz::Random r(0);
  cuhksz::Random r2(0);
  cuhksz::UniformDistribution d1(r);
  cuhksz::UniformDistribution d2(r2, 0, 1);
  EXPECT_DOUBLE_EQ(d1.next(), d2.next());
}

TEST(UniformDistribution, min) {
  cuhksz::UniformDistribution dist(100);
  EXPECT_DOUBLE_EQ(dist.min(), 0);
  cuhksz::UniformDistribution dist2(2, 3);
  EXPECT_DOUBLE_EQ(dist2.min(), 2);
  cuhksz::UniformDistribution dist3;
  EXPECT_DOUBLE_EQ(dist3.min(), 0);
}

TEST(UniformDistribution, max) {
  cuhksz::UniformDistribution dist(100);
  EXPECT_DOUBLE_EQ(dist.max(), 100);
  cuhksz::UniformDistribution dist2(2, 3);
  EXPECT_DOUBLE_EQ(dist2.max(), 3);
  cuhksz::UniformDistribution dist3;
  EXPECT_DOUBLE_EQ(dist3.max(), 1);
}
