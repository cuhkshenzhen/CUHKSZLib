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
  if (n_ == 0) return 0;
  int sum = 0;
  for (int i = 0; i < n_; i++) {
    if (randomGenerator->nextDouble() > p_) sum++;
  }
  return sum;
}
}  // namespace cuhksz
