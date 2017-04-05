#ifndef CUHKSZ_RANDOM_UNIFORMDISTRIBUTION
#define CUHKSZ_RANDOM_UNIFORMDISTRIBUTION

#include "random/Distribution.h"
#include "random/Random.h"

namespace cuhksz {
class UniformDistribution : public Distribution<double> {
 public:
  explicit UniformDistribution(double max = 1) : Distribution() {
    init(0, max);
  }

  UniformDistribution(double min, double max) : Distribution() {
    init(min, max);
  }

  explicit UniformDistribution(Random& r, double max = 1) : Distribution(r) {
    init(0, max);
  }
  UniformDistribution(Random& r, double min, double max) : Distribution(r) {
    init(min, max);
  }
  virtual ~UniformDistribution() {}

  double next() override;
  double min() { return min_; }
  double max() { return max_; }

 private:
  double min_;
  double max_;
  void init(double min, double max);
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_UNIFORMDISTRIBUTION
