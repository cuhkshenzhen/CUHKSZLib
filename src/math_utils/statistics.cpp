#include <cmath>
#include "math_utils/math_functions.h"

namespace cuhksz {


double mean(const double* arr, int size) { return sum(arr, size) / size; }
double mean(const int* arr, int size) { return (double)sum(arr, size) / size; }

double variance(const double* arr, int size) {
  double sum_square = 0.0;
  double means = mean(arr, size);
  for (int i = 0; i < size; i++) {
    double mean_diff = arr[i] - means;
    sum_square += mean_diff * mean_diff;
  }
  return sum_square / size;
}

double variance(const int* arr, int size) {
  double sum_square = 0.0;
  for (int i = 0; i < size; i++) {
    sum_square += arr[i] * arr[i];
  }
  double means = mean(arr, size);
  return sum_square / size - means * means;
}

double stddev(const double* arr, int size) {
  return std::sqrt(variance(arr, size));
}
double stddev(const int* arr, int size) {
  return std::sqrt(variance(arr, size));
}

double sample_variance(const double* arr, int size) {
  double sum_square = 0.0;
  double means = mean(arr, size);
  for (int i = 0; i < size; i++) {
    double mean_diff = arr[i] - means;
    sum_square += mean_diff * mean_diff;
  }
  return sum_square / (size - 1);
}
double sample_variance(const int* arr, int size) {
  double sum_square = 0.0;
  double means = mean(arr, size);
  for (int i = 0; i < size; i++) {
    double mean_diff = arr[i] - means;
    sum_square += mean_diff * mean_diff;
  }
  return sum_square / (size - 1);
}

double sample_stddev(const double* arr, int size) {
  return std::sqrt(sample_variance(arr, size));
}
double sample_stddev(const int* arr, int size) {
  return std::sqrt(sample_variance(arr, size));
}

}  // namespace cuhksz
