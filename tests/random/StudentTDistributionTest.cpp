#include <cmath>
#include "gtest/gtest.h"
#include "math_utils/math_functions.h"
#include "random.h"

TEST(StudentTDistribution, real_theory) {
  double r = 1;
  const int COUNT = 100000;
  cuhksz::StudentTDistribution student(r);
  int bucket[11];
  for (int i = 0; i < 10; i++) bucket[i] = 0;
  for (int i = 0; i < COUNT; i++) {
    double rnd = student.next();
    if (rnd >= -5 && rnd < 6) {
      bucket[(int)std::floor(rnd) + 5] += 1;
    }
  }
  double error_sum = 0;
  double theories[] = {0.0151, 0.0244, 0.0452, 0.1024, 0.2500, 0.2500,
                       0.1024, 0.0452, 0.0244, 0.0151, 0.0103};
  for (int i = 0; i < 10; i++) {
    double real = double(bucket[i]) / COUNT;
    double theory = theories[i];
    error_sum += std::abs(real - theory) / theory;
  }
  EXPECT_LT(error_sum / 10, 0.05);
}
