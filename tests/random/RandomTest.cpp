#include "gtest/gtest.h"
#include "math_utils/math_functions.h"
#include "random/Random.h"

TEST(Random, stddev) {
  cuhksz::Random r;
  int bucket[100];
  for (int i = 0; i < 100; i++) bucket[i] = 0;
  for (int i = 0; i < 100000; i++) {
    bucket[r.nextInt(100)] += 1;
  }
  EXPECT_LT(cuhksz::stddev(bucket, 100) / cuhksz::mean(bucket, 100), 0.05);
}

TEST(Random, construct_with_seed_and_setSeed) {
  cuhksz::Random r(0);
  bool a = r.nextBool();
  r.setSeed(0);
  bool b = r.nextBool();
  EXPECT_EQ(a, b);
}

TEST(Random, dump_test_nextInt) {
  cuhksz::Random r;
  r.nextInt();  // just test it can run without error
}

TEST(Random, nextInt_min_max) {
  cuhksz::Random r;
  for (int i = 0; i < 10000; i++) {
    int result = r.nextInt(-1000, 1000);
    ASSERT_LT(result, 1000);
    ASSERT_LE(-1000, result);
  }
}

TEST(Random, nextInt_max) {
  cuhksz::Random r;
  for (int i = 0; i < 10000; i++) {
    int result = r.nextInt(1000);
    ASSERT_LT(result, 1000);
    ASSERT_LE(-1000, result);
  }
}

TEST(RandomDeathTest, nextInt_invalid) {
  cuhksz::Random r;
  EXPECT_EXIT(r.nextInt(0), ::testing::ExitedWithCode(EXIT_FAILURE),
              "positive");
  EXPECT_EXIT(r.nextInt(-1), ::testing::ExitedWithCode(EXIT_FAILURE),
              "positive");
  EXPECT_EXIT(r.nextInt(0, -1), ::testing::ExitedWithCode(EXIT_FAILURE),
              "larger");
  EXPECT_EXIT(r.nextInt(1, 1), ::testing::ExitedWithCode(EXIT_FAILURE),
              "larger");
}

TEST(Random, nextDouble_min_max) {
  cuhksz::Random r;
  EXPECT_DOUBLE_EQ(r.nextDouble(5, 5), 5);
  for (int i = 0; i < 10000; i++) {
    int result = r.nextDouble(-5, 5);
    ASSERT_LT(result, 5);
    ASSERT_LE(-5, result);
  }
}

TEST(Random, nextDouble_max) {
  cuhksz::Random r;
  EXPECT_DOUBLE_EQ(r.nextDouble(0), 0);
  for (int i = 0; i < 10000; i++) {
    int result = r.nextDouble(5);
    ASSERT_LT(result, 5);
    ASSERT_LE(0, result);
  }
}

TEST(Random, nextDouble) {
  cuhksz::Random r;
  for (int i = 0; i < 10000; i++) {
    int result = r.nextDouble();
    ASSERT_LT(result, 1);
    ASSERT_LE(0, result);
  }
}

TEST(RandomDeathTest, nextDouble_invalid) {
  cuhksz::Random r;
  EXPECT_EXIT(r.nextDouble(-1), ::testing::ExitedWithCode(EXIT_FAILURE),
              "non-negative");
  EXPECT_EXIT(r.nextDouble(0, -1), ::testing::ExitedWithCode(EXIT_FAILURE),
              "larger than or equal to");
}
