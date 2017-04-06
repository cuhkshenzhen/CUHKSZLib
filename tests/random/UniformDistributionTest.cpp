#include "gtest/gtest.h"
#include "math_utils/math_functions.h"
#include "random.h"

TEST(UniformDistribution, stddev) {
  cuhksz::UniformIntDistribution ud(100);
  int bucket[100];
  for (int i = 0; i < 100; i++) bucket[i] = 0;
  for (int i = 0; i < 100000; i++) {
    bucket[ud.next()] += 1;
  }
  EXPECT_LT(cuhksz::stddev(bucket, 100) / cuhksz::mean(bucket, 100), 0.05);
}
