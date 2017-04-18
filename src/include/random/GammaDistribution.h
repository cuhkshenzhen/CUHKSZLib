#ifndef CUHKSZ_RANDOM_GAMMADISTRIBUTION
#define CUHKSZ_RANDOM_GAMMADISTRIBUTION

#include "random/Distribution.h"
namespace cuhksz {
class GammaDistribution : public Distribution<double> {
 public:
  GammaDistribution(double k, double theta) : Distribution() { init(k, theta); }
  GammaDistribution(Random& r, double k, double theta) : Distribution(r) {
    init(k, theta);
  }
  virtual ~GammaDistribution() {}

  double next() override;

  // shape
  double k() { return k_; }
  // scale
  double theta() { return theta_; }

 private:
  double k_;
  double theta_;

  void init(double k, double theta);
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_GAMMADISTRIBUTION
