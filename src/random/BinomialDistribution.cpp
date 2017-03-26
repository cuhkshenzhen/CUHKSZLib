#include "random/BinomialDistribution.h"

#include <cmath>
#include "math_utils/math_functions.h"

namespace cuhksz {
void BinomialDistribution::init(int n, double p) {
  if (n < 0 || p < 0 || p > 1) {
    exit(1);  // TODO: error here
  }
  n_ = n;
  p_ = p;
}

int BinomialDistribution::next() {
  double p_complement = 1.0 - p_;
  double rnd = randomGenerator->nextDouble();

  double threshold = 0;
  for (int i = 0; i < n_; i++) {
    threshold +=
        binomial(n_, i) * std::pow(p_, i) * std::pow(p_complement, n_ - i);
    if (rnd < threshold) return i;
  }
  return n_;
}
}  // namespace cuhksz
