#ifndef CUHKSZ_RANDOM_EXPONENTIALDISTRIBUTION
#define CUHKSZ_RANDOM_EXPONENTIALDISTRIBUTION

#include "random/GammaDistribution.h"
namespace cuhksz {
class ExponentialDistribution : public GammaDistribution {
 public:
  explicit ExponentialDistribution(double lambda)
      : GammaDistribution(1.0, 1 / lambda) {}
  ExponentialDistribution(Random& r, double lambda)
      : GammaDistribution(r, 1.0, 1 / lambda) {}
  virtual ~ExponentialDistribution() {}

  double lambda() { return 1 / GammaDistribution::theta(); }
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_EXPONENTIALDISTRIBUTION
