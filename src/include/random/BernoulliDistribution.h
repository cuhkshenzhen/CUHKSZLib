#ifndef RANDOM_BERNOULLIDISTRIBUTION
#define RANDOM_BERNOULLIDISTRIBUTION

#include "random/Distribution.h"
namespace cuhksz {
class BernoulliDistribution : public Distribution<bool> {
 public:
  explicit BernoulliDistribution(double p = 0.5) : Distribution() { init(p); }
  explicit BernoulliDistribution(Random& r, double p = 0.5) : Distribution(r) {
    init(p);
  }
  virtual ~BernoulliDistribution() {}

  bool next();

  double p() { return p_; }

 private:
  double p_;
  void init(double p);
};
}  // namespace cuhksz
#endif  // RANDOM_BERNOULLIDISTRIBUTION
