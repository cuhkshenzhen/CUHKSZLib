#ifndef CUHKSZ_MATH_BIGNUM
#define CUHKSZ_MATH_BIGNUM

namespace cuhksz {

#include <iostream>
#include <fstream>
#include <string>

class BigNum {
public:
    BigNum();
    BigNum(char* input);
    BigNum(long long input);

    ~BigNum();

    friend BigNum& operator+(const BigNum& a, const BigNum& b);
    friend BigNum& operator-(const BigNum& a, const BigNum& b);
    friend BigNum& operator*(const BigNum& a, const BigNum& b);
    friend BigNum& operator/(const BigNum& a, const BigNum& b);

    friend BigNum& operator+(const BigNum& a, const long long &b);
    friend BigNum& operator-(const BigNum& a, const long long &b);
    friend BigNum& operator*(const BigNum& a, const long long &b);
    friend BigNum& operator/(const BigNum& a, const long long &b);

    friend BigNum& operator+(const long long &a, const BigNum& b);
    friend BigNum& operator-(const long long &a, const BigNum& b);
    friend BigNum& operator*(const long long &a, const BigNum& b);
    friend BigNum& operator/(const long long &a, const BigNum& b);

    friend BigNum operator+=(BigNum& a, const BigNum& b);
    friend BigNum operator-=(BigNum& a, const BigNum& b);
    friend BigNum operator*=(BigNum& a, const BigNum& b);
    friend BigNum operator/=(BigNum& a, const BigNum& b);

    friend BigNum operator+=(long long &a, const BigNum &b);
    friend BigNum operator-=(long long &a, const BigNum &b);
    friend BigNum operator*=(long long &a, const BigNum &b);
    friend BigNum operator/=(long long &a, const BigNum &b);

    friend std::ostream operator<<(const ostream& os, const BigNum& output);
    friend std::istream operator>>(const istream& is, BigNum& input);

    friend long long intval();
private:
    string element;
};


}	// namespace cuhksz


#endif // CUHKSZ_MATH_BIGNUM
