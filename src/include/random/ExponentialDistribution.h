#ifndef CUHKSZ_RANDOM_EXPONENTIALDISTRIBUTION
#define CUHKSZ_RANDOM_EXPONENTIALDISTRIBUTION

#include "random/GammaDistribution.h"
namespace cuhksz {

/**
  Samples the random real number according to [Exponential
  distribution](https://en.wikipedia.org/wiki/Exponential_distribution).
  It has parameter `lambda`, the rate. The Exponential
  distribution is a special case of Gamma distribution as \f$k=1\f$ and
  \f$\theta=1/\lambda\f$. So this class is also a subclass of GammaDistribution.

  PDF:<br/>
  \f$f(x)=\lambda e^{-\lambda x}\f$

  where \f$\lambda\f$ is the parameter `lambda`.

  Usage:
  ```
  ExponentialDistribution dist(1.5);
  dist.next();
  ```
**/
class ExponentialDistribution : public GammaDistribution {
 public:
  /**
    Construct a Exponential distribution sampler with a new `Random` generator.
    @param lambda The rate
  **/
  explicit ExponentialDistribution(double lambda)
      : GammaDistribution(1.0, 1 / lambda) {}

  /**
    Construct a Exponential distribution sampler with an existing `Random`
    generator.
    @param[in] r The `Random` generator to use.
    @param lambda The rate
  **/
  ExponentialDistribution(Random& r, double lambda)
      : GammaDistribution(r, 1.0, 1 / lambda) {}

  virtual ~ExponentialDistribution() {}

  /**
    Returns the parameter `lambda`
  **/
  double lambda() { return 1 / GammaDistribution::theta(); }
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_EXPONENTIALDISTRIBUTION
