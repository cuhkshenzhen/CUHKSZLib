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
    the least common multiple of `a` and `b`. Note that if `a` and `b` are both
    0, it will cause division by zero error.
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

/**
  Array summation function with a mapping function.
  Sum up all the value in an array after mapping each with function `fn`.
  `ArrType` and `ReturnType` should be arithmetic types (e.g. `int`, `short`,
  `float`, `double`, etc.). You need to specify the `ReturnType`.

  Usage:
  ```
  int sum[] = {1, 2, 4, 3};
  cuhksz::sum<double>(sum, 4, [](int a) { return a / 2.0; });
  ```
  @param arr The array to be summed
  @param size Number of element(s) in `arr` to be summed
  @param fn Mapping function, should be type `ReturnType fn(ArrType)`
  @return The summation of first `size` element(s) after mapping in `arr`, with
    the type the same as the element of `arr`. If `size` <= 0, return 0.
**/
template <typename ReturnType, typename ArrType, typename Function>
ReturnType sum(const ArrType* arr, int size, Function fn) {
  ReturnType sum = 0;
  for (int i = 0; i < size; i++) {
    sum += fn(arr[i]);
  }
  return sum;
}

// TODO: vector sum

/**
  Compute the mean of elements in an array.
  `Type` should be an arithmetic type (e.g. `int`, `short`, `float`, `double`,
  etc.).
  @param arr The array to calculate the mean
  @param size Number of element(s) in `arr` to calculate
  @return The mean of first `size` element(s) in `arr`. If `size` < 0, return 0.
    If `size` == 0, it will cause division by zero error.
**/
template <typename Type>
double mean(const Type* arr, int size) {
  return (double)sum(arr, size) / size;
}

/**
  Compute the population variance for a `double` array.
  The population variance is defined as:
  \f[\frac{1}{N}\sum_{i=0}^{N-1}(x_i-\mu)^2\f]
  where \f$N\f$ is `size`, \f$\mu\f$ is `mean(arr, size)`, and \f$x_i\f$ is
  `arr[i]`.

  @param arr The array to calculate the population variance
  @param size Number of element(s) in `arr` to calculate
  @return The population variance of first `size` element(s) in `arr`. If `size`
    < 0, return 0. If `size` == 0, it will cause division by zero error.
  @sa sample_variance(const double*, int size)
  @sa stddev(const double*, int size)
  @sa variance(const int*, int size)
**/
double variance(const double* arr, int size);

/**
  Compute the population variance for a `int` array.
  The population variance is defined as:
  \f[\frac{1}{N}\sum_{i=0}^{N-1}(x_i-\mu)^2\f]
  where \f$N\f$ is `size`, \f$\mu\f$ is `mean(arr, size)`, and \f$x_i\f$ is
  `arr[i]`.

  @param arr The array to calculate the population variance
  @param size Number of element(s) in `arr` to calculate
  @return The population variance of first `size` element(s) in `arr`. If `size`
    < 0, return 0. If `size` == 0, it will cause division by zero error.
  @sa sample_variance(const int*, int size)
  @sa stddev(const int*, int size)
  @sa variance(const double*, int size)
**/
double variance(const int* arr, int size);

/**
  Compute the population standard deviation for a `double` array.
  The population standard deviation is the square root of the population
  variance.
  @param arr The array to calculate the population standard deviation
  @param size Number of element(s) in `arr` to calculate
  @return The population standard deviation of first `size` element(s) in `arr`.
    If `size` < 0, return 0. If `size` == 0, it will cause division by zero
    error.
  @sa sample_stddev(const double*, int size)
  @sa variance(const double*, int size)
  @sa stddev(const int*, int size)
**/
double stddev(const double* arr, int size);

/**
  Compute the population standard deviation for a `int` array.
  The population standard deviation is the square root of the population
  variance.
  @param arr The array to calculate the population standard deviation
  @param size Number of element(s) in `arr` to calculate
  @return The population standard deviation of first `size` element(s) in `arr`.
    If `size` < 0, return 0. If `size` == 0, it will cause division by zero
    error.
  @sa sample_stddev(const int*, int size)
  @sa variance(const int*, int size)
  @sa stddev(const double*, int size)
**/
double stddev(const int* arr, int size);

/**
  Compute the sample variance for a `double` array.
  The sample variance is defined as:
  \f[\frac{1}{N-1}\sum_{i=0}^{N-1}(x_i-\mu)^2\f]
  where \f$N\f$ is `size`, \f$\mu\f$ is `mean(arr, size)`, and \f$x_i\f$ is
  `arr[i]`.

  @param arr The array to calculate the sample variance
  @param size Number of element(s) in `arr` to calculate
  @return The sample variance of first `size` element(s) in `arr`. If `size`
    < 0, return 0. If `size` == 0, it will cause division by zero error.
  @sa variance(const double*, int size)
  @sa sample_stddev(const double*, int size)
  @sa sample_variance(const int*, int size)
**/
double sample_variance(const double* arr, int size);

/**
  Compute the sample variance for a `int` array.
  The sample variance is defined as:
  \f[\frac{1}{N-1}\sum_{i=0}^{N-1}(x_i-\mu)^2\f]
  where \f$N\f$ is `size`, \f$\mu\f$ is `mean(arr, size)`, and \f$x_i\f$ is
  `arr[i]`.

  @param arr The array to calculate the sample variance
  @param size Number of element(s) in `arr` to calculate
  @return The sample variance of first `size` element(s) in `arr`. If `size`
    < 0, return 0. If `size` == 0, it will cause division by zero error.
  @sa variance(const int*, int size)
  @sa sample_stddev(const int*, int size)
  @sa sample_variance(const double*, int size)
**/
double sample_variance(const int* arr, int size);

/**
  Compute the sample standard deviation for a `double` array.
  The sample standard deviation is the square root of the sample variance.
  @param arr The array to calculate the sample standard deviation
  @param size Number of element(s) in `arr` to calculate
  @return The sample standard deviation of first `size` element(s) in `arr`.
    If `size` < 0, return 0. If `size` == 0, it will cause division by zero
    error.
  @sa stddev(const double*, int size)
  @sa sample_variance(const double*, int size)
  @sa sample_stddev(const int*, int size)
**/
double sample_stddev(const double* arr, int size);

/**
  Compute the sample standard deviation for a `int` array.
  The sample standard deviation is the square root of the sample variance.
  @param arr The array to calculate the sample standard deviation
  @param size Number of element(s) in `arr` to calculate
  @return The sample standard deviation of first `size` element(s) in `arr`.
    If `size` < 0, return 0. If `size` == 0, it will cause division by zero
    error.
  @sa stddev(const int*, int size)
  @sa sample_variance(const int*, int size)
  @sa sample_stddev(const double*, int size)
**/
double sample_stddev(const int* arr, int size);

/**
  Binary power algorithm specified for 64-bit integers.
  Binary power algorithm, or [Exponentiation by
  squaring](https://en.wikipedia.org/wiki/Exponentiation_by_squaring) is a
  method to compute the integer power of large integers fast and with high
  precision. This function is optimized for 64-bit integers for efficiency.

  @param base The base number to be powered
  @param exp The exponent, should be non-negative
  @return The powered integer
  @sa genericBinaryPow(BaseType base, IntType exp)
**/
int64_t binaryPow(int64_t base, int exp);

/**
  Binary power algorithm for all types.
  Binary power algorithm, or [Exponentiation by
  squaring](https://en.wikipedia.org/wiki/Exponentiation_by_squaring) is a
  method to compute the integer power of large integers fast and with high
  precision.

  This function applies to all kinds of types that implement `*` operation
  (e.g. Fraction), not only integers. Because all types do not have the same way
  to construct a "one" object (e.g. identity matrix of Matrix), it cannot
  calculate the 0 power.

  `BaseType` can be any type that implements `*` operation. And `IntType` should
  be a ordinary integer type like `int`, `short`, etc. If you use integer
  literal as `base` argument, you may need to annotate the type of it like
  `2LL`, otherwise, the result may overflow the default integer type `int`.

  @param base The base "number" to be powered
  @param exp The exponent, should be positive
  @return The powered "number", the same type as `base`
  @sa binaryPow(int64_t base, int exp)
**/
template <typename BaseType, typename IntType>
BaseType genericBinaryPow(BaseType base, IntType exp) {
  // if (exp == 0) return 1;
  if (exp == 1) return base;
  if (exp <= 0)
    error("The Exponent for genericBinaryPow can only be positive.");
  exp -= 1;
  BaseType result = base;

  while (exp != 0) {
    if (exp % 2 == 1) {
      result *= base;
    }
    base *= base;
    exp /= 2;
  }
  return result;
}

/**
  Factorial function.
  Compute the factorial of integer: \f$n!\f$. `IntType` should be an ordinary
  integer type.
  @param n Non-negative integer
**/
template <typename IntType>
IntType factorial(IntType n) {
  if (n < 0) error("Argument of factorial cannot be negative.");
  IntType fac = 1;
  for (IntType i = 2; i <= n; i++) fac *= i;
  return fac;
}

// TODO: name may need change
/**
  Compute the permutation number, nPr.
  The permutation number is the number of ways to choose `r` things from `n`
  things and then permutate the `r` things. \f$n\text{P}r=\frac{n!}{r!}\f$.
  @param n Number of things to choose from
  @param r Number of things to choose and permutate
**/
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

/**
  Compute the combination number, aka binomial coefficient.
  Combination number, or binomial number, is the number of ways to choose `r`
  things from `n` things, or the coefficient of \f$a^rb^{n-r}\f$ in the
  expansion of \f$(a+b)^n\f$.
  \f${n \choose r}=n\text{C}r=\frac{n!}{r!(n-r)!}\f$.
  @param n Number of things to choose from
  @param r Number of things to choose
**/
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
