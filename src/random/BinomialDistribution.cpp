#include "random/BinomialDistribution.h"

#include <cmath>
#include "math_utils/math_functions.h"
#include "utils/error.h"

namespace cuhksz {
void BinomialDistribution::init(int n, double p) {
  if (n < 0 || p < 0 || p > 1) {
    error("Invalid parameter(s) for BinomialDistribution");
  }
  n_ = n;
  p_ = p;

  // generate probability lookup table
  lookup_table.reset(new double[n_ + 1]);
  double threshold = 0;
  double p_complement = 1 - p_;
  for (int i = 0; i < n_; i++) {
    threshold +=
        binomial(n_, i) * std::pow(p_, i) * std::pow(p_complement, n_ - i);
    lookup_table[i] = threshold;
  }
  lookup_table[n_] = 1;
}

int BinomialDistribution::next() {
  double rnd = randomGenerator->nextDouble();
  for (int i = 0; i < n_; i++) {
    if (rnd < lookup_table[i]) return i;
  }
  return n_;
}
}  // namespace cuhksz
