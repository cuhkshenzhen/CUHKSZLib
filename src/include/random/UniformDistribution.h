#ifndef RANDOM_UNIFORMDISTRIBUTION
#define RANDOM_UNIFORMDISTRIBUTION

#include "random/Random.h"

namespace cuhksz {
class UniformDistribution {
 public:
  UniformDistribution() : UniformDistribution(0, 1) {}
  UniformDistribution(double min, double max)
      : UniformDistribution(*(new Random()), min, max) {
    newedRandom = true;
  }

  explicit UniformDistribution(Random& r) : UniformDistribution(r, 0, 1) {}
  UniformDistribution(Random&, double, double);
  ~UniformDistribution();

  double next();
  double min() { return min_; }
  double max() { return max_; }

  void setRandomGenerator(Random&);

 private:
  double min_;
  double max_;
  bool newedRandom;
  Random* randomGenerator;
};
}  // namespace cuhksz

#endif  // RANDOM_UNIFORMDISTRIBUTION
