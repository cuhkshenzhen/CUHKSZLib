#include <cmath>
#include "math_functions.h"

namespace cuhksz {

#define IMPLEMENT_SUM(Type)               \
  double sum(const Type* arr, int size) { \
    Type sum = 0.0;                       \
    for (int i = 0; i < size; i++) {      \
      sum += arr[i];                      \
    }                                     \
    return sum;                           \
  }

IMPLEMENT_SUM(int)
IMPLEMENT_SUM(double)

double mean(const double* arr, int size) { return sum(arr, size) / size; }

double stddev(const double* arr, int size) {
  double sum_square = 0.0;
  for (int i = 0; i < size; i++) {
    sum_square += arr[i] * arr[i];
  }
  double means = mean(arr, size);
  return std::sqrt(sum_square / size - means * means);
}

}  // namespace cuhksz
