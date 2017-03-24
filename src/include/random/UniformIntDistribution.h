#ifndef RANDOM_UNIFORMINTDISTRIBUTION
#define RANDOM_UNIFORMINTDISTRIBUTION

#include "random/Distribution.h"
#include "random/Random.h"

namespace cuhksz {
class UniformIntDistribution : public Distribution<int> {
 public:
  explicit UniformIntDistribution(int max) : Distribution() { init(0, max); }

  UniformIntDistribution(int min, int max) : Distribution() { init(min, max); }

  UniformIntDistribution(Random& r, int max) : Distribution(r) { init(0, max); }
  UniformIntDistribution(Random& r, int min, int max) : Distribution(r) {
    init(min, max);
  }
  virtual ~UniformIntDistribution() {}

  int next() override;
  int min() { return min_; }
  int max() { return max_; }

 private:
  int min_;
  int max_;
  void init(int min, int max);
};
}  // namespace cuhksz

#endif  // RANDOM_UNIFORMINTDISTRIBUTION
