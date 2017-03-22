#ifndef RANDOM_UNIFORMDISTRIBUTION
#define RANDOM_UNIFORMDISTRIBUTION

#include "random/Distribution.h"
#include "random/Random.h"

namespace cuhksz {
class UniformDistribution : public Distribution {
 public:
  UniformDistribution() : Distribution() { init(0, 1); }

  UniformDistribution(double min, double max) : Distribution() {
    init(min, max);
  }

  explicit UniformDistribution(Random& r) : Distribution(r) { init(0, 1); }
  UniformDistribution(Random& r, double min, double max) : Distribution(r) {
    init(min, max);
  }
  virtual ~UniformDistribution(){};

  double next() override;
  double min() { return min_; }
  double max() { return max_; }

 private:
  double min_;
  double max_;
  void init(double min, double max);
};
}  // namespace cuhksz

#endif  // RANDOM_UNIFORMDISTRIBUTION
