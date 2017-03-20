#include "math/math_functions.h"

namespace cuhksz {
int64_t binaryPow(int64_t base, int exp) {
  if (exp == 0) return 1;
  if (exp < 0) return 0;  // TODO: raise error here
  if (base == 1) return 1;
  if (base == 2) return base << (exp - 1);

  int64_t result = 1;
  while (exp) {     // exp !=0
    if (exp & 1) {  // exp % 2 == 1
      result *= base;
    }
    base *= base;
    exp >>= 1;  // exp /= 2
  }
  return result;
}
}  // namespace cuhksz
