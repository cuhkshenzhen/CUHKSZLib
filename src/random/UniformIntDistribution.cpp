#include "random/UniformIntDistribution.h"

namespace cuhksz {

void UniformIntDistribution::init(int min, int max) {
  if (min >= max) {
    exit(1);  // TODO: error here
  }
  min_ = min;
  max_ = max;
}

int UniformIntDistribution::next() {
  return randomGenerator->nextInt(min_, max_);
}

}  // namespace cuhksz
