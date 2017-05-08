#include "math_utils/math_functions.h"
#include "gtest/gtest.h"

TEST(MathFunctions, gcd) {
  EXPECT_EQ(cuhksz::gcd(10, 100), 10);
  EXPECT_EQ(cuhksz::gcd(20, 12), 4);
  EXPECT_EQ(cuhksz::gcd(17, 41), 1);
  EXPECT_EQ(cuhksz::gcd(10, 0), 10);
  EXPECT_EQ(cuhksz::gcd(0, 10), 10);
}

TEST(MathFunctions, lcm) {
  EXPECT_EQ(cuhksz::lcm(10, 100), 100);
  EXPECT_EQ(cuhksz::lcm(3, 5), 15);
  EXPECT_EQ(cuhksz::lcm(3, 0), 0);
  EXPECT_EQ(cuhksz::lcm(0, 5), 0);
}

TEST(MathFunctionsDeathTest, lcm_both_zero) {
  EXPECT_DEATH(cuhksz::lcm(0, 0), "");
}

TEST(MathFunctions, sum_int) {
  int sum[] = {1, 2, 4, 3};
  EXPECT_EQ(cuhksz::sum(sum, 4), 10);
  EXPECT_EQ(cuhksz::sum(sum, 0), 0);
  EXPECT_EQ(cuhksz::sum(sum, -1), 0);
}

TEST(MathFunctions, sum_double) {
  double sum[] = {1.2, 2, 4.2, 3.1};
  EXPECT_DOUBLE_EQ(cuhksz::sum(sum, 4), 10.5);
  EXPECT_DOUBLE_EQ(cuhksz::sum(sum, 0), 0);
  EXPECT_DOUBLE_EQ(cuhksz::sum(sum, -1), 0);
}

TEST(MathFunctions, sum_int_to_double) {
  int sum[] = {1, 2, 4, 3};
  double result = cuhksz::sum(sum, 4, [](int a) { return a / 2.0; });
  EXPECT_DOUBLE_EQ(result, 5.0);
}

TEST(MathFunctions, mean_int) {
  int arr[] = {1, 2, 3, 4};
  EXPECT_DOUBLE_EQ(cuhksz::mean(arr, 4), 2.5);
  EXPECT_DOUBLE_EQ(cuhksz::mean(arr, -1), 0);
}

TEST(MathFunctions, mean_double) {
  double arr[] = {0.92478335, 0.83805631, 0.95966262, 0.95925219, 0.78004427};
  EXPECT_DOUBLE_EQ(cuhksz::mean(arr, 5), 0.892359748);
  EXPECT_DOUBLE_EQ(cuhksz::mean(arr, -1), 0);
}

TEST(MathFunctions, stddev_int) {
  int arr[] = {1, 2, 3, 4};
  EXPECT_DOUBLE_EQ(cuhksz::stddev(arr, 4), 1.1180339887498949);
}

TEST(MathFunctions, stddev_double) {
  double arr[] = {0.92478335, 0.83805631, 0.95966262, 0.95925219, 0.78004427};
  EXPECT_DOUBLE_EQ(cuhksz::stddev(arr, 5), 0.071580996528149116);
}

TEST(MathFunctions, variance_int) {
  int arr[] = {1, 2, 3, 4};
  EXPECT_DOUBLE_EQ(cuhksz::variance(arr, 4), 1.25);
}

TEST(MathFunctions, variance_double) {
  double arr[] = {0.92478335, 0.83805631, 0.95966262, 0.95925219, 0.78004427};
  EXPECT_DOUBLE_EQ(cuhksz::variance(arr, 5), 0.0051238390639628956);
}

TEST(MathFunctions, sample_stddev_int) {
  int arr[] = {1, 2, 3, 4};
  EXPECT_DOUBLE_EQ(cuhksz::sample_stddev(arr, 4), 1.2909944487358056);
}

TEST(MathFunctions, sample_stddev_double) {
  double arr[] = {0.92478335, 0.83805631, 0.95966262, 0.95925219, 0.78004427};
  EXPECT_DOUBLE_EQ(cuhksz::sample_stddev(arr, 5), 0.08002998706705892);
}

TEST(MathFunctions, sample_variance_int) {
  int arr[] = {1, 2, 3, 4};
  EXPECT_DOUBLE_EQ(cuhksz::sample_variance(arr, 4), 1.25 * 4 / 3);
}

TEST(MathFunctions, sample_variance_double) {
  double arr[] = {0.92478335, 0.83805631, 0.95966262, 0.95925219, 0.78004427};
  EXPECT_DOUBLE_EQ(cuhksz::sample_variance(arr, 5),
                   0.0051238390639628956 * 5 / 4);
}

TEST(MathFunctions, binaryPow) {
  EXPECT_EQ(cuhksz::binaryPow(100, 0), 1);
  EXPECT_EQ(cuhksz::binaryPow(2, 32), 4294967296);
  EXPECT_EQ(cuhksz::binaryPow(2, 62), 4611686018427387904);
  EXPECT_EQ(cuhksz::binaryPow(-3, 27), -7625597484987);
}

TEST(MathFunctionsDeathTest, binaryPow_negative) {
  EXPECT_EXIT(cuhksz::binaryPow(10, -1),
              ::testing::ExitedWithCode(EXIT_FAILURE), "negative");
}

TEST(MathFunctions, generalBinaryPow) {
  EXPECT_EQ(cuhksz::genericBinaryPow(2LL, 32), 4294967296);
  EXPECT_EQ(cuhksz::genericBinaryPow(2LL, 62), 4611686018427387904);
  EXPECT_EQ(cuhksz::genericBinaryPow(3LL, 27), 7625597484987);
}

TEST(MathFunctionsDeathTest, generalBinaryPow_nonpositive) {
  EXPECT_EXIT(cuhksz::genericBinaryPow(10, -1),
              ::testing::ExitedWithCode(EXIT_FAILURE), "positive");
  EXPECT_EXIT(cuhksz::genericBinaryPow(10, 0),
              ::testing::ExitedWithCode(EXIT_FAILURE), "positive");
}

TEST(MathFunctions, factorial) {
  EXPECT_EQ(cuhksz::factorial(10LL), 3628800);
  EXPECT_EQ(cuhksz::factorial(20LL), 2432902008176640000);
}

TEST(MathFunctionsDeathTest, factorial_negative) {
  EXPECT_EXIT(cuhksz::factorial(-1), ::testing::ExitedWithCode(EXIT_FAILURE),
              "negative");
}

TEST(MathFunctions, permutation) {
  EXPECT_EQ(cuhksz::permutation(5, 2), 20);
  EXPECT_EQ(cuhksz::permutation(20LL, 5LL), 1860480);
}

TEST(MathFunctionsDeathTest, permutation_invalid) {
  EXPECT_EXIT(cuhksz::permutation(2, 3),
              ::testing::ExitedWithCode(EXIT_FAILURE), "invalid");
  EXPECT_EXIT(cuhksz::permutation(-2, 3),
              ::testing::ExitedWithCode(EXIT_FAILURE), "invalid");
  EXPECT_EXIT(cuhksz::permutation(2, -3),
              ::testing::ExitedWithCode(EXIT_FAILURE), "invalid");
}

TEST(MathFunctions, combination) {
  EXPECT_EQ(cuhksz::binomial(5, 2), 10);
  EXPECT_EQ(cuhksz::binomial(20LL, 15LL), 15504);
  EXPECT_EQ(cuhksz::binomial(10, 6), cuhksz::binomial(10, 4));
  EXPECT_EQ(cuhksz::binomial(11, 5), cuhksz::binomial(11, 6));
}

TEST(MathFunctionsDeathTest, combination_invalid) {
  EXPECT_EXIT(cuhksz::binomial(2, 3), ::testing::ExitedWithCode(EXIT_FAILURE),
              "invalid");
  EXPECT_EXIT(cuhksz::binomial(-2, 3), ::testing::ExitedWithCode(EXIT_FAILURE),
              "invalid");
  EXPECT_EXIT(cuhksz::binomial(2, -3), ::testing::ExitedWithCode(EXIT_FAILURE),
              "invalid");
}
