#include <cmath>
#include "gtest/gtest.h"
#include "math_utils/math_functions.h"
#include "random.h"

TEST(GeometricDistribution, real_theory) {
  double p = 0.5;
  const int COUNT = 100000;
  cuhksz::GeometricDistribution geodist(p);
  int bucket[5];
  for (int i = 0; i < 5; i++) bucket[i] = 0;
  for (int i = 0; i < COUNT; i++) {
    int rnd = geodist.next();
    if (rnd < 5) bucket[rnd] += 1;
  }
  double error_sum = 0;
  for (int i = 0; i < 5; i++) {
    double real = double(bucket[i]) / COUNT;
    double theory = p * std::pow(1 - p, i);
    error_sum += std::abs(real - theory) / theory;
  }
  EXPECT_LT(error_sum / 5, 0.05);
}
