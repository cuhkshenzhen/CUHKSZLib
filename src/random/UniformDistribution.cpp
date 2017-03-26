#include "random/UniformDistribution.h"

namespace cuhksz {

void UniformDistribution::init(double min, double max) {
  if (min > max) {
    exit(1);  // TODO: error here
  }
  min_ = min;
  max_ = max;
}

double UniformDistribution::next() {
  return randomGenerator->nextDouble(min_, max_);
}

}  // namespace cuhksz
