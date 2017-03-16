#ifndef CUHKSZ_MATH_FUNCTIONS
#define CUHKSZ_MATH_FUNCTIONS

#include <array>

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

double sum(const double*, int size);
double sum(const int*, int size);

double mean(const double*, int size);
double stddev(const double*, int size);


}  // namespace cuhksz
#endif  // CUHKSZ_MATH_FUNCTIONS
