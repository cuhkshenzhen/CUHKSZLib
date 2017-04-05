#ifndef CUHKSZ_RANDOM_GEOMETRICDISTRIBUTION
#define CUHKSZ_RANDOM_GEOMETRICDISTRIBUTION

#include "random/NegativeBinomialDistribution.h"
#include "random/Random.h"

namespace cuhksz {
class GeometricDistribution : public NegativeBinomialDistribution {
 public:
  explicit GeometricDistribution(double p = 0.5)
      : NegativeBinomialDistribution(1, p) {}

  explicit GeometricDistribution(Random& r, double p = 0.5)
      : NegativeBinomialDistribution(r, 1, p) {}
  virtual ~GeometricDistribution() {}

  double p() { return NegativeBinomialDistribution::p(); }
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_GEOMETRICDISTRIBUTION
