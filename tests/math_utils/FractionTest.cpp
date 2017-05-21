#include "math_utils/Fraction.h"

#include "gtest/gtest.h"

TEST(Fraction, initialize) {
    cuhksz::Fraction a, b(3), c(2, 3);
    EXPECT_TRUE(a.getNumerator() == 0 && a.getDenominator() == 1);
    EXPECT_TRUE(b.getNumerator() == 3 && b.getDenominator() == 1);
    EXPECT_TRUE(c.getNumerator() == 2 && c.getDenominator() == 3);
}

TEST(Fraction, addition) {
    cuhksz::Fraction a(2, 3), b(1, 2), c;
    c = a + b;
    EXPECT_TRUE(c.getNumerator() == 7 && c.getDenominator() == 6);

    a = cuhksz::Fraction(1, 4);
    b = cuhksz::Fraction(1, 4);
    a += b;
    EXPECT_TRUE(a.getNumerator() == 1 && a.getDenominator() == 2);
}

TEST(Fraction, subtraction) {
    cuhksz::Fraction a(2, 3), b(1, 2), c;
    c = a - b;
    EXPECT_TRUE(c.getNumerator() == 1 && c.getDenominator() == 6);

    a = cuhksz::Fraction(1, 4);
    b = cuhksz::Fraction(1, 2);
    a -= b;
    EXPECT_TRUE(a.getNumerator() == -1 && a.getDenominator() == 4);
}

TEST(Fraction, multiplication) {
    cuhksz::Fraction a(2, 3), b(1, 2), c;
    c = a * b;
    EXPECT_TRUE(c.getNumerator() == 1 && c.getDenominator() == 3);

    a = cuhksz::Fraction(1, -4);
    b = cuhksz::Fraction(1, 4);
    a *= b;
    EXPECT_TRUE(a.getNumerator() == -1 && a.getDenominator() == 16);
}

TEST(Fraction, division) {
    cuhksz::Fraction a(2, 3), b(1, 2), c;
    c = a / b;
    EXPECT_TRUE(c.getNumerator() == 4 && c.getDenominator() == 3);

    a = cuhksz::Fraction(1, -4);
    b = cuhksz::Fraction(1, 4);
    a /= b;
    EXPECT_TRUE(a.getNumerator() == -1 && a.getDenominator() == 1);
}

TEST(Fraction, compare) {
    cuhksz::Fraction a(2, 3), b(1, 2), c(-1, 3), d(5, 4), e(5, 4);
    EXPECT_TRUE(a > b);
    EXPECT_TRUE(b >= c);
    EXPECT_TRUE(d > a);
    EXPECT_TRUE(c <= a);
    EXPECT_TRUE(b < d);
    EXPECT_TRUE(a != e);
    EXPECT_TRUE(d == e);
}
