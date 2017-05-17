#include "random/random_functions.h"
#include "gtest/gtest.h"
#include "math_utils/math_functions.h"

TEST(random_functions, stddev) {
  int bucket[100];
  for (int i = 0; i < 100; i++) bucket[i] = 0;
  for (int i = 0; i < 100000; i++) {
    bucket[cuhksz::randomInt(100)] += 1;
  }
  EXPECT_LT(cuhksz::stddev(bucket, 100) / cuhksz::mean(bucket, 100), 0.05);
}

TEST(random_functions, dump_test_randomBool) {
  cuhksz::randomBool();  // just test it can run without error
}

TEST(random_functions, randomInt_min_max) {
  for (int i = 0; i < 10000; i++) {
    int result = cuhksz::randomInt(-1000, 1000);
    ASSERT_LT(result, 1000);
    ASSERT_LE(-1000, result);
  }
}

TEST(random_functions, randomInt_max) {
  for (int i = 0; i < 10000; i++) {
    int result = cuhksz::randomInt(1000);
    ASSERT_LT(result, 1000);
    ASSERT_LE(-1000, result);
  }
}

TEST(random_functionsDeathTest, randomInt_invalid) {
  EXPECT_EXIT(cuhksz::randomInt(0), ::testing::ExitedWithCode(EXIT_FAILURE),
              "positive");
  EXPECT_EXIT(cuhksz::randomInt(-1), ::testing::ExitedWithCode(EXIT_FAILURE),
              "positive");
  EXPECT_EXIT(cuhksz::randomInt(0, -1), ::testing::ExitedWithCode(EXIT_FAILURE),
              "larger");
  EXPECT_EXIT(cuhksz::randomInt(1, 1), ::testing::ExitedWithCode(EXIT_FAILURE),
              "larger");
}

TEST(random_functions, randomDouble_min_max) {
  EXPECT_DOUBLE_EQ(cuhksz::randomDouble(5, 5), 5);
  for (int i = 0; i < 10000; i++) {
    int result = cuhksz::randomDouble(-5, 5);
    ASSERT_LT(result, 5);
    ASSERT_LE(-5, result);
  }
}

TEST(random_functions, randomDouble_max) {
  EXPECT_DOUBLE_EQ(cuhksz::randomDouble(0), 0);
  for (int i = 0; i < 10000; i++) {
    int result = cuhksz::randomDouble(5);
    ASSERT_LT(result, 5);
    ASSERT_LE(0, result);
  }
}

TEST(random_functions, randomDouble) {
  for (int i = 0; i < 10000; i++) {
    int result = cuhksz::randomDouble();
    ASSERT_LT(result, 1);
    ASSERT_LE(0, result);
  }
}

TEST(random_functionsDeathTest, randomDouble_invalid) {
  EXPECT_EXIT(cuhksz::randomDouble(-1), ::testing::ExitedWithCode(EXIT_FAILURE),
              "larger than or equal to");
  EXPECT_EXIT(cuhksz::randomDouble(0, -1),
              ::testing::ExitedWithCode(EXIT_FAILURE),
              "larger than or equal to");
}
