#include <cmath>
#include "gtest/gtest.h"
#include "math_utils/math_functions.h"
#include "random.h"

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
