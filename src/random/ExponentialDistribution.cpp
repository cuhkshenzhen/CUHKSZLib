#include "random/ExponentialDistribution.h"

#include <cmath>

namespace cuhksz {
void ExponentialDistribution::init(double lambda) {
  if (lambda <= 0) {
    exit(1);  // TODO: error here
  }
  lambda_ = lambda;
}

double ExponentialDistribution::next() {
  double rnd = randomGenerator->nextDouble();
  return -std::log(1 - rnd) / lambda_;
}
}  // namespace cuhksz
