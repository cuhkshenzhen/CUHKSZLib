#include <cmath>
#include "gtest/gtest.h"
#include "math_utils/math_functions.h"
#include "random.h"

TEST(BinomialDistribution, real_theory) {
  double p = 0.5;
  double p_complement = 1.0 - p;
  int n = 10;
  const int COUNT = 100000;
  cuhksz::BinomialDistribution binodist(n, p);
  int bucket[11];
  for (int i = 0; i < 11; i++) bucket[i] = 0;
  for (int i = 0; i < COUNT; i++) {
    bucket[binodist.next()] += 1;
  }
  double error_sum = 0;
  for (int i = 0; i < 11; i++) {
    double real = double(bucket[i]) / COUNT;
    double theory =
        cuhksz::binomial(n, i) * std::pow(p, i) * std::pow(p_complement, n - i);
    error_sum += std::abs(real - theory) / theory;
  }
  EXPECT_LT(error_sum / 11, 0.05);
}
