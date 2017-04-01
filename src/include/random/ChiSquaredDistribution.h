#ifndef CUHKSZ_RANDOM_CHISQUAREDDISTRIBUTION
#define CUHKSZ_RANDOM_CHISQUAREDDISTRIBUTION

#include "random/GammaDistribution.h"
namespace cuhksz {
class ChiSquaredDistribution : public GammaDistribution {
 public:
  explicit ChiSquaredDistribution(double r) : GammaDistribution(r / 2.0, 2.0) {}
  ChiSquaredDistribution(Random& rnd, double r)
      : GammaDistribution(rnd, r / 2.0, 2.0) {}
  virtual ~ChiSquaredDistribution() {}

  double r() { return GammaDistribution::k() * 2; }
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_CHISQUAREDDISTRIBUTION
