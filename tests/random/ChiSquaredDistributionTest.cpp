#include <cmath>
#include "gtest/gtest.h"
#include "math_utils/math_functions.h"
#include "random.h"

TEST(ChiSquaredDistribution, real_theory) {
  int r = 4;
  const int COUNT = 100000;
  cuhksz::ChiSquaredDistribution chi2(r);
  int bucket[11];
  for (int i = 0; i < 11; i++) bucket[i] = 0;
  for (int i = 0; i < COUNT; i++) {
    double rnd = chi2.next();
    if (rnd >= 0 && rnd < 11) {
      bucket[(int)rnd] += 1;
    }
  }
  double error_sum = 0;
  double theories[] = {0.090204,  0.174037,  0.177933, 0.15182,
                       0.118708,  0.0881492, 0.06326,  0.04431,
                       0.0304787, 0.0206718, 0.0138637};
  for (int i = 0; i < 11; i++) {
    double real = double(bucket[i]) / COUNT;
    double theory = theories[i];
    error_sum += std::abs(real - theory) / theory;
  }
  EXPECT_LT(error_sum / 11, 0.05);
}
