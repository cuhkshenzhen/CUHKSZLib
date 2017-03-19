#ifndef CUHKSZ_MATH_FRACTION
#define CUHKSZ_MATH_FRACTION

#include <cmath>

namespace cuhksz {

class Fraction {
public:
	Fraction() : numerator(0), denominator(1) { }

	Fraction(int const integer) : numerator(integer), denominator(1) { }	// allow implicit conversion

	Fraction(int const numerator, int const denominator) :
		numerator(numerator), denominator(denominator)
	{
		if (denominator == 0) {
			std::cerr << "Divide by Zero error" << '\n';
			exit(1);
		}
		int divisor = gcd(numerator, denominator);
		numerator /= divisor, denominator /= divisor;
	}

	Fraction& operator+(Fraction const &other) const {
		return Fraction(numerator * other.denominator + denominator * other.numerator, denominator * other.denominator);
	}

	friend Fraction& operator+(int value, Fraction const &self) {
		return self + value;
	}

	void operator+=(Fraction const &other) {
		this = &Fraction(numerator * other.denominator + denominator * other.numerator, denominator * other.denominator);
	}

	Fraction& operator-(Fraction const &other) const {
		return Fraction(numerator * other.denominator - denominator * other.numerator, denominator * other.denominator);
	}

	friend Fraction& operator-(int value, Fraction const &self) {
		return self - value;
	}

	void operator-=(Fraction const &other) {
		this = &Fraction(numerator * other.denominator - denominator * other.numerator, denominator * other.denominator);
	}

	Fraction& operator*(Fraction const &other) const {
		return Fraction(numerator * other.numerator, denominator * other.denominator);
	}

	friend Fraction& operator*(int value, Fraction const &self) {
		return self * value;
	}

	void operator*=(Fraction const &other) {
		this = &Fraction(numerator * other.numerator, denominator * other.denominator);
	}

	Fraction& operator/(Fraction const &other) const {
		return Fraction(numerator * other.denominator, denominator * other.numerator);
	}

	friend Fraction& operator/(int value, Fraction const &self) {
		return self / value;
	}

	void operator/=(Fraction const &other) {
		this = &Fraction(numerator * other.denominator, denominator * other.numerator);
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

	friend std::ostream& operator<<(std::ostream& os, Fraction const &self) {
		return os << self.numerator << "/" << self.denominator;
	}

private:
	int numerator, denominator;
};


}	// namespace cuhksz


#endif // CUHKSZ_MATH_FRACTION
