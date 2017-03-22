#include "random/BernoulliDistribution.h"

namespace cuhksz {
void BernoulliDistribution::init(double p) {
  if (p < 0) {
    exit(1);  // TODO: error here
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
