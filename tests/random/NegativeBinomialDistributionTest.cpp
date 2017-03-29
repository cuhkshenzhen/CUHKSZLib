#include <cmath>
#include "gtest/gtest.h"
#include "math_utils/math_functions.h"
#include "random.h"

TEST(NegativeBinomialDistribution, real_theory) {
  int r = 5;
  double p = 0.5;
  const int COUNT = 100000;
  cuhksz::NegativeBinomialDistribution negbi(r, p);
  int bucket[11];
  for (int i = 0; i < 11; i++) bucket[i] = 0;
  for (int i = 0; i < COUNT; i++) {
    int rnd = negbi.next();
    if (rnd <= 10) bucket[rnd] += 1;
  }
  double error_sum = 0;
  double p_r = std::pow(p, r);
  for (int i = 0; i < 11; i++) {
    double real = double(bucket[i]) / COUNT;
    double theory =
        cuhksz::binomial(i + r - 1, r - 1) * p_r * std::pow(1 - p, i);
    error_sum += std::abs(real - theory) / theory;
  }
  EXPECT_LT(error_sum / 11, 0.05);
}
