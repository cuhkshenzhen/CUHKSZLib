#include "random/UniformIntDistribution.h"

#include "utils/error.h"

namespace cuhksz {

void UniformIntDistribution::init(int min, int max) {
  if (min >= max) {
    error("Invalid parameter(s) for UniformIntDistribution");
  }
  min_ = min;
  max_ = max;
}

int UniformIntDistribution::next() {
  return randomGenerator->nextInt(min_, max_);
}

}  // namespace cuhksz
