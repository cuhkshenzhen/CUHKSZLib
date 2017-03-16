#include <cstdio>
#include "gtest/gtest.h"
#include "math_functions.h"
#include "random.h"

TEST(Random, stddev) {
  cuhksz::Random r;
  double bucket[100];
  for (int i = 0; i < 100; i++) bucket[i] = 0;
  for (int i = 0; i < 1000000; i++) {
    bucket[cuhksz::randomInt(100)] += 1;
  }
  ASSERT_LT(cuhksz::stddev(bucket, 100) / cuhksz::mean(bucket, 100), 0.05);
}
