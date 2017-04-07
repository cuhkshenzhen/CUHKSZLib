#ifndef CUHKSZ_MATH_BIGNUM
#define CUHKSZ_MATH_BIGNUM

#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

namespace cuhksz {

template<int MAX_SIZE>
class BigNum {
public:
    BigNum() {
        memset(elem, 0, MAX_SIZE * sizeof(int));
        sign = 1;
        len = 0;
    }

    BigNum(const long long x) {
        len = 0;
        sign = x < 0 ? -1 : 1;
        memset(elem, 0, MAX_SIZE * sizeof(int));
        for (long long i = std::abs(x); i; i /= BigNum::base)
            elem[len ++] = i % BigNum::base;
    }

    BigNum(const std::string & s) {
        sign = s[0] == '-' ? -1 : 1;
        len = 0;
        memset(elem, 0, MAX_SIZE * sizeof(int));
        for (int i = s.size() - 1; i >= BigNum::order - 1 + (s[0] == '-'); i -= BigNum::order)
            elem[len ++] = s.substr(i - BigNum::order + 1, BigNum::order);
        if ((s.size() - (s[0] == '-')) % BigNum::order)
            elem[len ++] = s.substr((s[0] == '-'), (s.size() - (s[0] == '-')) % BigNum::order);
    }

    BigNum(const BigNum &src) {
        sign = src.sign;
        len = src.len;
        memcpy(elem, src.elem, len * sizeof(int));
    }

    ~BigNum() { }

    // allocation
    BigNum& operator= (const BigNum& src) const {
        sign = src.sign;
        len = src.len;
        memcpy(elem, src.elem, len * sizeof(int));
        return *this;
    }

    // index
    int& operator[] (const int index) const {
        return elem[index];
    }

    // output
    friend std::ostream& operator<< (std::ostream& os, const BigNum& src) {
        os << src.toString();
        return os;
    }

    // compare
    bool operator< (const BigNum& other) const {
        return cmp(*this, other) < 0;
    }

    bool operator<= (const BigNum& other) const {
        return cmp(*this, other) <= 0;
    }

    bool operator> (const BigNum& other) const {
        return cmp(*this, other) > 0;
    }

    bool operator>= (const BigNum& other) const {
        return cmp(*this, other) >= 0;
    }

    bool operator== (const BigNum& other) const {
        return cmp(*this, other) == 0;
    }

    bool operator!= (const BigNum& other) const {
        return cmp(*this, other) != 0;
    }

    // addition
    BigNum& operator+ (const BigNum& other) const {
        BigNum ret;
        if (sign == other.sign) {
            ret = add(*this, other);
        } else {
            if (sign < 0)
                ret = sub(other, *this);
            else
                ret = sub(*this, other);
        }
        return ret;
    }

    BigNum& operator+ (const long long smallNum) const {
        BigNum ret, other = BigNum(smallNum);
        if (sign == other.sign) {
            ret = add(*this, other);
        } else {
            if (sign < 0)
                ret = sub(other, *this);
            else
                ret = sub(*this, other);
        }
        return ret;
    }

    BigNum& operator+= (const BigNum& other) {
        if (sign == other.sign) {
            *this = add(*this, other);
        } else {
            if (sign < 0)
                *this = sub(other, *this);
            else
                *this = sub(*this, other);
        }
        return *this;
    }

    BigNum& operator+= (const long long smallNum) {
        BigNum other = BigNum(smallNum);
        if (sign == other.sign) {
            *this = add(*this, other);
        } else {
            if (sign < 0)
                *this = sub(other, *this);
            else
                *this = sub(*this, other);
        }
        return *this;
    }

    // subtraction
    BigNum& operator- (const BigNum& other) const {
        BigNum ret;
        if (sign == other.sign) {
            if (sign < 0)
                ret = sub(other, *this);
            else
                ret = sub(*this, other);
        }
        else {
            ret = add(*this, other);
        }
        return ret;
    }

    BigNum& operator- (const long long smallNum) const {
        BigNum ret, other = BigNum(smallNum);
        if (sign == other.sign) {
            if (sign < 0)
                ret = sub(other, *this);
            else
                ret = sub(*this, other);
        }
        else {
            ret = add(*this, other);
        }
        return ret;
    }

    BigNum& operator-= (const BigNum& other) {
        if (sign == other.sign) {
            if (sign < 0)
                *this = sub(other, *this);
            else
                *this = sub(*this, other);
        }
        else {
            *this = add(*this, other);
        }
        return *this;
    }

    BigNum& operator-= (const long long smallNum) {
        BigNum other = BigNum(smallNum);
        if (sign == other.sign) {
            if (sign < 0)
                *this = sub(other, *this);
            else
                *this = sub(*this, other);
        }
        else {
            *this = add(*this, other);
        }
        return *this;
    }

    // multiplication
    BigNum& operator* (const BigNum& other) const {
        BigNum ret = mul(*this, other);
        return ret;
    }

    BigNum& operator* (const long long smallNum) const {
        BigNum ret, other = BigNum(smallNum);
        ret = mul(*this, other);
        return ret;
    }

    BigNum& operator*= (const BigNum& other) const {
        *this = mul(*this, other);
        return *this;
    }

    BigNum& operator*= (const long long smallNum) {
        BigNum other = BigNum(smallNum);
        *this = mul(*this, other);
        return *this;
    }

    // other
    BigNum& operator- () const {
        BigNum ret = *this;
        ret.sign = -ret.sign;
        return ret;
    }

    BigNum& operator++ () { // prefix ++
        *this += 1;
        return *this;
    }

    BigNum& operator++ (int) { // postfix ++
        BigNum ret = *this;
        ++ (*this);
        return ret;
    }

    BigNum& operator-- () {
        *this -= 1;
        return *this;
    }

    BigNum& operator-- (int) {
        BigNum ret = *this;
        -- (*this);
        return ret;
    }


    friend int cmp(const BigNum& a, const BigNum& b, bool isAbs=false) {
        if (!isAbs && a.sign != b.sign) return a.sign > b.sign ? 1 : -1;
        if (a.len != b.len) return a.len > b.len ? a.sign : -a.sign;
        for (int i = a.len - 1; i >= 0; i --)
            if (a[i] != b[i])
                return a[i] > b[i] ? a.sign : -a.sign;
        return 0;
    }

    friend BigNum& add(const BigNum& a, const BigNum& b) {
        BigNum ret;
        ret.len = std::max(a.len, b.len);
        for (int i = 0; i < ret.len; i ++)
            ret[i] = a[i] + b[i];
        for (int i = 0; i < ret.len; i ++)
            if (ret[i] >= BigNum::base) {
                ret[i] -= BigNum::base;
                ret[i + 1] ++;
            }
        if (ret[ret.len]) ret.len ++;
        ret.sign = a.sign;
        return ret;
    }

    friend BigNum& sub(const BigNum& a, const BigNum& b) {
        BigNum ret, *l, *s;

        if (cmp(a, b, true) < 0) {
            l = &b, s = &a;
            ret.sign = -1;
        } else l = &a, s = &b;

        ret.len = l->len;
        for (int i = 0; i < ret.len; i ++)
            ret[i] = (*l)[i] - (*s)[i];
        for (int i = 0; i < ret.len; i ++)
            if (ret[i] < 0) {
                ret[i] += BigNum::base;
                ret[i + 1] --;
            }
        while (ret.len > 0 && !ret[ret.len-1]) ret.len --;
        return ret;
    }

    friend BigNum& mul(const BigNum& a, const BigNum& b) {
        BigNum ret;
        if (a.len == 0 || b.len == 0)
            return ret;

        ret.len = a.len + b.len - 1;
        for (int i = 0; i < a.len; i ++)
            for (int j = 0; j < b.len; j ++) {
                ret[i + j] += a[i] * b[j];
            }
        for (int i = 0; i < ret.len; i ++) {
            ret[i + 1] += ret[i] / BigNum::base;
            ret[i] %= BigNum::base;
        }
        if (ret[ret.len]) ret.len ++;
        ret.sign = a.sign;
        return ret;
    }

    BigNum& abs() const {
        sign = 1;
        return *this;
    }

    friend BigNum& abs(const BigNum& a) {
        return a.abs();
    }

    std::string toString() const {
        std::string s;
        if (sign < 0) s += "-";
        for (int i = len - 1, j = 0; i >= 0; i --, j ++)
            s[j] += std::to_string(elem[i]);
        return s;
    }

    friend std::string toString(const BigNum& src) {
        return src.toString();
    }



private:
    int elem[MAX_SIZE];
    int len;
    int sign;
    static int base;
    static int order;
};

template<int MAX_SIZE>
int BigNum<MAX_SIZE>::base = 10;

template<int MAX_SIZE>
int BigNum<MAX_SIZE>::order = 1;

}	// namespace cuhksz


#endif // CUHKSZ_MATH_BIGNUM
