#include "random/UniformDistribution.h"

#include "utils/error.h"

namespace cuhksz {

void UniformDistribution::init(double min, double max) {
  if (min > max) {
    error("Invalid parameter(s) for UniformDistribution");
  }
  min_ = min;
  max_ = max;
}

double UniformDistribution::next() {
  return randomGenerator->nextDouble(min_, max_);
}

}  // namespace cuhksz
