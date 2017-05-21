#include "math_utils/BigNum.h"

#include "gtest/gtest.h"

TEST(BigNum, initialize) {
  cuhksz::BigNum<5> a, b(12345), c("-12345");
  EXPECT_EQ(b[1], 4);
  EXPECT_EQ(c[3], 2);
}

TEST(BigNum, addition) {
  cuhksz::BigNum<10> a(21312), b(9123421), c;
  c = a + b;
  EXPECT_EQ(c, 21312 + 9123421);

  a = -1231321;
  b = 131231235;
  c = a + b;
  EXPECT_EQ(c, -1231321 + 131231235);
}

TEST(BigNum, subtraction) {
  cuhksz::BigNum<10> a(21312), b(9123421), c;
  c = a - b;
  EXPECT_EQ(c, 21312 - 9123421);

  a = -1231321;
  b = 131231235;
  c = a - b;
  EXPECT_EQ(c, -1231321 - 131231235);
}

TEST(BigNum, multiplication) {
  cuhksz::BigNum<20> a(21312), b(9123421), c;
  c = a * b;
  EXPECT_EQ(c, 21312LL * 9123421);

  a = -1231321;
  b = 131231235;
  c = a * b;
  EXPECT_EQ(c, -1231321LL * 131231235);
}

TEST(BigNum, compare) {
  cuhksz::BigNum<10> a(12312), b(5187381), c(-94214143);
  EXPECT_TRUE(a < b);
  EXPECT_TRUE(a > c);
  EXPECT_TRUE(c < 0);
}
