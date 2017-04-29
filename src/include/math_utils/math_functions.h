#ifndef CUHKSZ_MATH_MATHFUNCTIONS
#define CUHKSZ_MATH_MATHFUNCTIONS

#include <array>
#include <cstdint>
#include <memory>
#include <type_traits>

#include "utils/error.h"

namespace cuhksz {

/**
  Greatest common divisor function using [Euclidean
  algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm).
  Parameters `a` and `b` should be both integers, and the return type is the
  more precise type in `a` and `b`.
  @return If one of the parameter is 0, returns the other one. Otherwise returns
  the greatest common divisor of `a` and `b`.
  @sa lcm(IntType1 a, IntType2 b)
**/
template <typename IntType1, typename IntType2>
auto gcd(IntType1 a, IntType2 b) ->
    typename std::common_type<IntType1, IntType2>::type {
  if (b)
    while ((a %= b) && (b %= a)) {
    }
  return a + b;
}

/**
  Least common multiple function.
  The result is simply calculated by `a * b / gcd(a, b)`. Parameters `a` and `b`
  should be both integers, and the return type is the more precise type in `a`
  and `b`.
  @return If one of the parameter is 0, returns the other one. Otherwise returns
  the least common multiple of `a` and `b`. Note that if `a` and `b` are both 0,
  it will cause division by zero error.
  @sa gcd(IntType1 a, IntType2 b)
**/
template <typename IntType1, typename IntType2>
auto lcm(IntType1 a, IntType2 b) ->
    typename std::common_type<IntType1, IntType2>::type {
  return a * b / gcd(a, b);
}

/**
  Array summation function.
  Sum up all the value in an array. `Type` should be an arithmetic type (e.g.
  `int`, `short`, `float`, `double`, etc.).
  @param arr The array to be summed
  @param size Number of element(s) in `arr` to be summed
  @return The summation of first `size` element(s) in `arr`, with the type the
  same as the element of `arr`. If `size` <= 0, return 0.
**/
template <typename Type>
Type sum(const Type* arr, int size) {
  Type sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum;
}


template <typename ArrType, typename ReturnType, typename Function>
ReturnType sum(const ArrType* arr, int size, Function fn) {
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
  if (exp <= 0)
    error("The Exponent for genericBinaryPow can only be positive.");
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

template <typename IntType>
IntType factorial(IntType n) {
  if (n < 0) error("Argument of factorial cannot be negative.");
  IntType fac = 1;
  for (IntType i = 2; i <= n; i++) fac *= i;
  return fac;
}

// TODO: name may need change
template <typename IntType>
IntType permutation(IntType n, IntType r) {
  if (n < 0 || r < 0 || r > n) error("Arguments invalid for permutation.");
  IntType result = n;
  n--;
  for (; r > 1; r--, n--) {
    result *= n;
  }
  return result;
}

template <typename IntType>
IntType binomial(IntType n, IntType r) {
  if (n < 0 || r < 0 || r > n) error("Arguments invalid for binomial.");
  if (r == 0) return 1;
  if (r > n / 2) return binomial(n, n - r);
  std::unique_ptr<IntType[]> combination(new IntType[r]);
  for (int i = 0; i < r; i++) combination[i] = 1;
  for (int i = 0; i < n - r; i++) {
    for (int j = 0; j < r; j++) {
      if (j == 0) {
        combination[j] += 1;
      } else {
        combination[j] += combination[j - 1];
      }
    }
  }

  return combination[r - 1];
}
}  // namespace cuhksz
#endif  // CUHKSZ_MATH_MATHFUNCTIONS
