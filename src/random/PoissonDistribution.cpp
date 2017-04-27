#include "random/PoissonDistribution.h"

#include <cmath>

#include "utils/error.h"

namespace cuhksz {
void PoissonDistribution::init(double lambda) {
  if (lambda <= 0) {
    error("Invalid parameter for PoissonDistribution");
  }
  lambda_ = lambda;
  expLambda = std::exp(-lambda_);
}

int PoissonDistribution::next() {
  double rnd = randomGenerator->nextDouble();
  int result = 0;
  double probability = expLambda;
  double threshold = expLambda;
  while (rnd >= threshold) {
    result += 1;
    probability *= lambda_ / result;
    threshold += probability;
  }
  return result;
}
}  // namespace cuhksz
