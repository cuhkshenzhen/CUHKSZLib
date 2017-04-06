#include "random/PoissonDistribution.h"

#include <cmath>

namespace cuhksz {
void PoissonDistribution::init(double lambda) {
  if (lambda <= 0) {
    exit(1);  // TODO: error here
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
