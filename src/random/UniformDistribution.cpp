#include "random/UniformDistribution.h"

namespace cuhksz {
UniformDistribution::UniformDistribution(Random& random, double min,
                                         double max) {
  if (min >= max) {
    exit(1);  // TODO: error here
  }
  min_ = min;
  max_ = max;
  randomGenerator = &random;
  newedRandom = false;
}

UniformDistribution::~UniformDistribution() {
  if (newedRandom) delete randomGenerator;
}

double UniformDistribution::next() {
  return randomGenerator->nextDouble(min_, max_);
}

void UniformDistribution::setRandomGenerator(Random& random) {
  newedRandom = false;
  randomGenerator = &random;
}

}  // namespace cuhksz
