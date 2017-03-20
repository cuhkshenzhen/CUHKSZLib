#include "math/math_functions.h"

namespace cuhksz {
int64_t binary_pow(int64_t base, int exp) {
  if (exp == 0) return 1;
  if (exp < 0) return 0;  // TODO: raise error here

  int64_t result = 1;
  while (exp != 0) {
    if (exp % 2 == 1) {
      result *= base;
    }
    base *= base;
    exp /= 2;
  }
  return result;
}
}  // namespace cuhksz
