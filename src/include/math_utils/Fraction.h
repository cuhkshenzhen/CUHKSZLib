#ifndef CUHKSZ_MATH_FRACTION
#define CUHKSZ_MATH_FRACTION

#include <cmath>
#include <fstream>
#include <iostream>
#include "math_utils/math_functions.h"
#include "utils/error.h"

namespace cuhksz {

class Fraction {
public:
    Fraction() : Fraction(0) { }

    Fraction(int const integer) : Fraction(integer, 1) { }  // allow implicit conversion

    Fraction(int const numerator, int const denominator)
        : numerator(numerator), denominator(denominator)
    {
        if (denominator == 0) {
            error("Divide by Zero error");
        }
        int divisor = gcd(numerator, denominator);
        Fraction::numerator /= divisor, Fraction::denominator /= divisor;
        if (Fraction::denominator < 0) {
            Fraction::numerator *= -1;
        }
        Fraction::denominator = abs(Fraction::denominator);
    }

    int getNumerator() { return numerator; }
    int getDenominator() { return denominator; }

    Fraction operator+(Fraction const &other) const {
        return Fraction(
            numerator * other.denominator + denominator * other.numerator,
            denominator * other.denominator);
    }

    friend Fraction operator+(int value, Fraction const &self) {
        return self + value;
    }

    void operator+=(Fraction const &other) {
        Fraction tmp(
                numerator * other.denominator + denominator * other.numerator,
                denominator * other.denominator);
        numerator = tmp.numerator;
        denominator = tmp.denominator;
    }

    Fraction operator-(Fraction const &other) const {
        return Fraction(
            numerator * other.denominator - denominator * other.numerator,
            denominator * other.denominator);
    }

    friend Fraction operator-(int value, Fraction const &self) {
        return self - value;
    }

    void operator-=(Fraction const &other) {
        Fraction tmp(
                numerator * other.denominator - denominator * other.numerator,
                denominator * other.denominator);
        numerator = tmp.numerator;
        denominator = tmp.denominator;
    }

    Fraction operator*(Fraction const &other) const {
        return Fraction(numerator * other.numerator,
                    denominator * other.denominator);
    }

    friend Fraction operator*(int value, Fraction const &self) {
        return self * value;
    }

    void operator*=(Fraction const &other) {
        Fraction tmp(numerator * other.numerator,
              denominator * other.denominator);
        numerator = tmp.numerator;
        denominator = tmp.denominator;
    }

    Fraction operator/(Fraction const &other) const {
        return Fraction(numerator * other.denominator,
                    denominator * other.numerator);
    }

    friend Fraction operator/(int value, Fraction const &self) {
        return self / value;
    }

    void operator/=(Fraction const &other) {
        Fraction tmp(numerator / other.numerator,
              denominator / other.denominator);
        numerator = tmp.numerator;
        denominator = tmp.denominator;
    }

    bool operator==(Fraction const &other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(Fraction const &other) const {
        return numerator != other.numerator || denominator != other.denominator;
    }

    bool operator<(Fraction const &other) const {
        return numerator * other.denominator < denominator * other.numerator;
    }

    bool operator<=(Fraction const &other) const {
        return numerator * other.denominator <= denominator * other.numerator;
    }

    bool operator>(Fraction const &other) const {
        return numerator * other.denominator > denominator * other.numerator;
    }

    bool operator>=(Fraction const &other) const {
        return numerator * other.denominator >= denominator * other.numerator;
    }

    friend std::ostream &operator<<(std::ostream &os, Fraction const &self) {
        return os << self.numerator << "/" << self.denominator;
    }

private:
    int numerator, denominator;
};

}  // namespace cuhksz

#endif  // CUHKSZ_MATH_FRACTION
