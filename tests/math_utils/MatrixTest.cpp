#include "math_utils/Matrix.h"

#include "gtest/gtest.h"

TEST(Matrix, initialize) {
  std::vector<std::vector<int> > a;
  a.clear();

  std::vector<int> tmp;
  tmp.clear();
  tmp.push_back(1), tmp.push_back(2), tmp.push_back(1);
  a.push_back(tmp);
  tmp.clear();
  tmp.push_back(2), tmp.push_back(-1), tmp.push_back(3);
  a.push_back(tmp);
  tmp.clear();
  tmp.push_back(-1), tmp.push_back(0), tmp.push_back(1);
  a.push_back(tmp);

  cuhksz::Matrix<int> A(a), B(3, 3);

  EXPECT_EQ(A[0][0], 1);
  EXPECT_EQ(A[0][2], 1);
  EXPECT_EQ(A[2][1], 0);

  B = A;
  EXPECT_TRUE(A == B);

  cuhksz::Matrix<int> C(A);
  EXPECT_TRUE(C == A);
}

TEST(Matrix, addition) {
  std::vector<std::vector<int> > a, b, c;
  a.clear(), b.clear(), c.clear();

  std::vector<int> tmp;
  tmp.clear();
  tmp.push_back(1), tmp.push_back(2), tmp.push_back(1);
  a.push_back(tmp);
  tmp.clear();
  tmp.push_back(2), tmp.push_back(-1), tmp.push_back(3);
  a.push_back(tmp);
  tmp.clear();
  tmp.push_back(-1), tmp.push_back(0), tmp.push_back(1);
  a.push_back(tmp);

  tmp.clear();
  tmp.push_back(-2), tmp.push_back(3), tmp.push_back(4);
  b.push_back(tmp);
  tmp.clear();
  tmp.push_back(9), tmp.push_back(-5), tmp.push_back(5);
  b.push_back(tmp);
  tmp.clear();
  tmp.push_back(10), tmp.push_back(33), tmp.push_back(34);
  b.push_back(tmp);

  tmp.clear();
  tmp.push_back(-1), tmp.push_back(5), tmp.push_back(5);
  c.push_back(tmp);
  tmp.clear();
  tmp.push_back(11), tmp.push_back(-6), tmp.push_back(8);
  c.push_back(tmp);
  tmp.clear();
  tmp.push_back(9), tmp.push_back(33), tmp.push_back(35);
  c.push_back(tmp);

  cuhksz::Matrix<int> A(a), B(b), C(c), D(3, 3);
  D = A + B;
  EXPECT_TRUE(C == D);
}

TEST(Matrix, subtraction) {
  std::vector<std::vector<int> > a, b, c;
  a.clear(), b.clear(), c.clear();

  std::vector<int> tmp;
  tmp.clear();
  tmp.push_back(1), tmp.push_back(2), tmp.push_back(1);
  a.push_back(tmp);
  tmp.clear();
  tmp.push_back(2), tmp.push_back(-1), tmp.push_back(3);
  a.push_back(tmp);
  tmp.clear();
  tmp.push_back(-1), tmp.push_back(0), tmp.push_back(1);
  a.push_back(tmp);

  tmp.clear();
  tmp.push_back(-2), tmp.push_back(3), tmp.push_back(4);
  b.push_back(tmp);
  tmp.clear();
  tmp.push_back(9), tmp.push_back(-5), tmp.push_back(5);
  b.push_back(tmp);
  tmp.clear();
  tmp.push_back(10), tmp.push_back(33), tmp.push_back(34);
  b.push_back(tmp);

  tmp.clear();
  tmp.push_back(3), tmp.push_back(-1), tmp.push_back(-3);
  c.push_back(tmp);
  tmp.clear();
  tmp.push_back(-7), tmp.push_back(4), tmp.push_back(-2);
  c.push_back(tmp);
  tmp.clear();
  tmp.push_back(-11), tmp.push_back(-33), tmp.push_back(-33);
  c.push_back(tmp);

  cuhksz::Matrix<int> A(a), B(b), C(c), D(3, 3);
  D = A - B;
  EXPECT_TRUE(C == D);
}

TEST(Matrix, multiplication) {
  std::vector<std::vector<int> > a, b, c;
  a.clear(), b.clear(), c.clear();

  std::vector<int> tmp;
  tmp.clear();
  tmp.push_back(1), tmp.push_back(2), tmp.push_back(1);
  a.push_back(tmp);
  tmp.clear();
  tmp.push_back(2), tmp.push_back(-1), tmp.push_back(3);
  a.push_back(tmp);
  tmp.clear();
  tmp.push_back(-1), tmp.push_back(0), tmp.push_back(1);
  a.push_back(tmp);

  tmp.clear();
  tmp.push_back(-2), tmp.push_back(3), tmp.push_back(4);
  b.push_back(tmp);
  tmp.clear();
  tmp.push_back(9), tmp.push_back(-5), tmp.push_back(5);
  b.push_back(tmp);
  tmp.clear();
  tmp.push_back(10), tmp.push_back(33), tmp.push_back(34);
  b.push_back(tmp);

  tmp.clear();
  tmp.push_back(26), tmp.push_back(26), tmp.push_back(48);
  c.push_back(tmp);
  tmp.clear();
  tmp.push_back(17), tmp.push_back(110), tmp.push_back(105);
  c.push_back(tmp);
  tmp.clear();
  tmp.push_back(12), tmp.push_back(30), tmp.push_back(30);
  c.push_back(tmp);

  cuhksz::Matrix<int> A(a), B(b), C(c), D(3, 3);
  D = A * B;
  EXPECT_TRUE(C == D);
}
