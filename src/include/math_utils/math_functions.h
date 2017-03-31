#ifndef CUHKSZ_MATH_MATHFUNCTIONS
#define CUHKSZ_MATH_MATHFUNCTIONS

#include <array>
#include <cstdint>
#include <functional>

namespace cuhksz {

template <typename IntType>
IntType gcd(IntType a, IntType b) {
  if (b)
    while ((a %= b) && (b %= a)) {
    }
  return a + b;
}

template <typename IntType>
IntType lcm(IntType a, IntType b) {
  return a * b / gcd(a, b);
}

int sum(const int*, int size);
double sum(const double*, int size);

template <typename ArrType, typename ReturnType>
ReturnType sum(const ArrType* arr, int size,
               const std::function<ReturnType(ArrType)>& fn) {
  ReturnType sum = 0;
  for (int i = 0; i < size; i++) {
    sum += fn(arr[i]);
  }
  return sum;
}

// TODO: vector sum

double mean(const double*, int size);
double mean(const int*, int size);

double variance(const double*, int size);
double variance(const int*, int size);

double stddev(const double*, int size);
double stddev(const int*, int size);

double sample_variance(const double*, int size);
double sample_variance(const int*, int size);

double sample_stddev(const double*, int size);
double sample_stddev(const int*, int size);

int64_t binaryPow(int64_t, int);

template <typename BaseType, typename IntType>
BaseType genericBinaryPow(BaseType base, IntType exp) {
  // if (exp == 0) return 1;
  if (exp == 1) return base;
  if (exp < 0) return 0;  // TODO: raise error here
  exp -= 1;

  BaseType result = base;

  while (exp != 0) {
    if (exp % 2 == 1) {  // exp % 2 == 1
      result *= base;
    }
    base *= base;
    exp /= 2;
  }
  return result;
}
}  // namespace cuhksz
#endif  // CUHKSZ_MATH_MATHFUNCTIONS
