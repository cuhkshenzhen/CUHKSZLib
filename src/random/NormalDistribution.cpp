#include "random/NormalDistribution.h"
#include <cmath>
namespace cuhksz {
void NormalDistribution::init(double mean, double stddev) {
  if (stddev <= 0) {
    exit(1);  // TODO: error here
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
  } while (sum == 0.0 || sum > 1);
  double result = std::sqrt(-2 * std::log(sum) / sum);
  spareResult = v * result;
  hasSpare = true;
  return u * result * stddev_ + mean_;
}
}  // namespace cuhksz
