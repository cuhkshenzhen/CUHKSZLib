#include "random/BernoulliDistribution.h"
#include "utils/error.h"

namespace cuhksz {
void BernoulliDistribution::init(double p) {
  if (p < 0 || p > 1) {
    error("Invalid parameter for BernoulliDistribution");
  }
  p_ = p;
}
bool BernoulliDistribution::next() {
  if (randomGenerator->nextDouble() < p_) {
    return true;
  } else {
    return false;
  }
}
}  // namespace cuhksz
