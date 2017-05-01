#ifndef CUHKSZ_RANDOM_GEOMETRICDISTRIBUTION
#define CUHKSZ_RANDOM_GEOMETRICDISTRIBUTION

#include "random/NegativeBinomialDistribution.h"
#include "random/Random.h"

namespace cuhksz {

/**
  Samples the random integer according to [Geometric
  distribution](https://en.wikipedia.org/wiki/Geometric_distribution).
  It has parameter `p`, the probability of success. And the sampled integer
  means the number of failures before success. So it is a special case of
  Negative binomial distribution as \f$r=1\f$, and thus this class is a
  subclass of the NegativeBinomialDistribution.

  PMF:<br/>
  \f$f(x)=p(1-p)^x\f$

  Usage:
  ```
  GeometricDistribution dist(0.5);
  dist.next();
  ```
**/
class GeometricDistribution : public NegativeBinomialDistribution {
 public:
  /**
    Construct a geometric distribution sampler with a new `Random` generator.
    @param p The probability of success
  **/
  explicit GeometricDistribution(double p = 0.5)
      : NegativeBinomialDistribution(1, p) {}

  /**
    Construct a geometric distribution sampler with an existing `Random`
    generator.
    @param[in] r The `Random` generator to use.
    @param p The probability of success
  **/
  explicit GeometricDistribution(Random& r, double p = 0.5)
      : NegativeBinomialDistribution(r, 1, p) {}

  virtual ~GeometricDistribution() {}

  /**
    Returns the parameter `p`.
  **/
  double p() { return NegativeBinomialDistribution::p(); }
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_GEOMETRICDISTRIBUTION
