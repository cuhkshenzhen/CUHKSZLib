#include <cmath>
#include "gtest/gtest.h"
#include "math_utils/math_functions.h"
#include "random.h"

TEST(ExponentialDistribution, real_theory) {
  double lambda = 0.5;
  const int COUNT = 100000;
  cuhksz::ExponentialDistribution exponential(lambda);
  int bucket[6];
  for (int i = 0; i < 6; i++) bucket[i] = 0;
  for (int i = 0; i < COUNT; i++) {
    double rnd = exponential.next();
    if (rnd >= 0 && rnd < 6) {
      bucket[(int)rnd] += 1;
    }
  }
  double error_sum = 0;
  for (int i = 0; i < 6; i++) {
    double real = double(bucket[i]) / COUNT;
    double theory = std::exp(-lambda * i) - std::exp(-lambda * (i + 1));
    error_sum += std::abs(real - theory) / theory;
  }
  EXPECT_LT(error_sum / 11, 0.05);
}
