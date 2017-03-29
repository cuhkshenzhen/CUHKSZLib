#include "random/NegativeBinomialDistribution.h"

#include <cmath>
#include "math_utils/math_functions.h"

namespace cuhksz {
void NegativeBinomialDistribution::init(int r, double p) {
  if (r <= 0 || p <= 0 || p > 1) {
    exit(1);  // TODO: error here
  }
  r_ = r;
  p_ = p;
  pPowr = genericBinaryPow(p, r);
}

int NegativeBinomialDistribution::next() {
  double rnd = randomGenerator->nextDouble();

  int result = 0;
  double p_complement = 1 - p_;
  double probability = pPowr;
  double threshold = pPowr;
  while (rnd >= threshold) {
    result += 1;
    probability *= p_complement * (r_ + result - 1) / result;
    threshold += probability;
  }
  return result;
}
}  // namespace cuhksz
