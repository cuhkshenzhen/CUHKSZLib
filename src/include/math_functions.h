#ifndef CUHKSZ_MATH_FUNCTIONS
#define CUHKSZ_MATH_FUNCTIONS

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

#define DECLARE_SUM(Type) Type sum(const Type*, int size);

DECLARE_SUM(int)
DECLARE_SUM(double)

#undef DECLARE_SUM

template <typename ArrType, typename ReturnType>
ReturnType sum(const ArrType* arr, int size,
               const std::function<ReturnType(ArrType)>& fn) {
  ReturnType sum = 0;
  for (int i = 0; i < size; i++) {
    sum += fn(arr[i]);
  }
  return sum;
}

double mean(const double*, int size);

double variance(const double*, int size);
double stddev(const double*, int size);

double sample_variance(const double*, int size);
double sample_stddev(const double*, int size);

int64_t pow(int64_t, int);

}  // namespace cuhksz
#endif  // CUHKSZ_MATH_FUNCTIONS
