#ifndef CUHKSZ_RANDOM_GAMMADISTRIBUTION
#define CUHKSZ_RANDOM_GAMMADISTRIBUTION

#include "random/Distribution.h"
namespace cuhksz {

/**
  Samples the random real numbers according to [Gamma
  distribution](https://en.wikipedia.org/wiki/Gamma_distribution).
  It has `k` as the **shape** parameter and `theta` as the **scale** parameter.
  See the `PDF` part for the details of the parameters.

  PDF:<br/>
  \f$f(x)=\frac{1}{\Gamma(k)\theta^k}x^{k-1}e^{-x/\theta}\f$

  where \f$\theta\f$ is the `theta` parameter.

  Usage:
  ```
  GammaDistribution dist(9, 0.5);
  dist.next();
  ```
**/
class GammaDistribution : public Distribution<double> {
 public:
  /**
    Construct a Gamma distribution sampler with a new `Random` generator.
    @param k The **shape** parameter
    @param theta The **scale** parameter
  **/
  GammaDistribution(double k, double theta) : Distribution() { init(k, theta); }

  /**
    Construct a Gamma distribution sampler with an existing `Random` generator.
    @param[in] r The `Random` generator to use.
    @param k The **shape** parameter
    @param theta The **scale** parameter
  **/
  GammaDistribution(Random& r, double k, double theta) : Distribution(r) {
    init(k, theta);
  }

  virtual ~GammaDistribution() {}

  /**
    Sample a real number according to Gamma distribution.
  **/
  double next() override;

  /**
    Returns the **shape** parameter `k`.
  **/
  double k() { return k_; }

  /**
    Returns the **scale** parameter `theta`.
  **/
  double theta() { return theta_; }

 private:
  double k_;
  double theta_;

  void init(double k, double theta);
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_GAMMADISTRIBUTION
