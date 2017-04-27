#include "random/NormalDistribution.h"

#include <cmath>
#include "utils/error.h"

namespace cuhksz {
void NormalDistribution::init(double mean, double stddev) {
  if (stddev <= 0) {
    error("Invalid parameter `stddev` for NormalDistribution");
  }
  mean_ = mean;
  stddev_ = stddev;
}

double NormalDistribution::next() {
  // Marsaglia polar method
  // (https://en.wikipedia.org/wiki/Marsaglia_polar_method)
  if (hasSpare) {
    hasSpare = false;
    return spareResult * stddev_ + mean_;
  }
  double u;
  double v;
  double sum;
  do {
    u = randomGenerator->nextDouble(-1, 1);
    v = randomGenerator->nextDouble(-1, 1);
    sum = u * u + v * v;
// disable gcc's warning for comparing with 0.0
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
  } while (sum == 0.0 || sum > 1);
#pragma GCC diagnostic pop

  double result = std::sqrt(-2 * std::log(sum) / sum);
  spareResult = v * result;
  hasSpare = true;
  return u * result * stddev_ + mean_;
}
}  // namespace cuhksz
