#ifndef CUHKSZ_RANDOM_CHISQUAREDDISTRIBUTION
#define CUHKSZ_RANDOM_CHISQUAREDDISTRIBUTION

#include "random/GammaDistribution.h"
namespace cuhksz {
/**
  Sampling the random real numbers according to [Chi-squared
  distribution](https://en.wikipedia.org/wiki/Chi-squared_distribution).
  It has parameter `r`, the "degrees of freedom" parameter. The Chi-squared
  distribution is a special case of Gamma distribution as \f$k=r/2\f$ and
  \f$\theta=2\f$. So this class is also a subclass of GammaDistribution.

  PDF:<br/>
  \f$f(x)=\frac{1}{\Gamma(\frac{r}{2})2^{r/2}}x^{r/2-1}e^{-x/2}\f$

  Usage:
  ```
  ChiSquaredDistribution dist(3);
  dist.next();
  ```
**/
class ChiSquaredDistribution : public GammaDistribution {
 public:
  /**
    Construct a Chi-squared distribution sampler with a new `Random` generator.
    @param r The degrees of freedom
  **/
  explicit ChiSquaredDistribution(double r) : GammaDistribution(r / 2.0, 2.0) {}

  /**
    Construct a Chi-squared distribution sampler with an existing `Random`
    generator.
    @param[in] rnd The `Random` generator to use.
    @param r The degrees of freedom
  **/
  ChiSquaredDistribution(Random& rnd, double r)
      : GammaDistribution(rnd, r / 2.0, 2.0) {}

  virtual ~ChiSquaredDistribution() {}

  /**
    Returns the parameter `r`
  **/
  double r() { return GammaDistribution::k() * 2; }
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_CHISQUAREDDISTRIBUTION
