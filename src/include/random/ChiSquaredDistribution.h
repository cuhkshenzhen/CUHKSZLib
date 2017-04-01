#ifndef CUHKSZ_RANDOM_CHISQUAREDDISTRIBUTION
#define CUHKSZ_RANDOM_CHISQUAREDDISTRIBUTION

#include "random/GammaDistribution.h"
namespace cuhksz {
class ChiSquaredDistribution : public GammaDistribution {
 public:
  explicit ChiSquaredDistribution(int r) : GammaDistribution(r / 2.0, 2.0) {}
  ChiSquaredDistribution(Random& rnd, int r)
      : GammaDistribution(rnd, r / 2.0, 2.0) {}
  virtual ~ChiSquaredDistribution() {}

  int r() { return GammaDistribution::k() * 2; }
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_CHISQUAREDDISTRIBUTION
