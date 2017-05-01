#ifndef CUHKSZ_RANDOM_POISSONDISTRIBUTION
#define CUHKSZ_RANDOM_POISSONDISTRIBUTION

#include "random/Distribution.h"

namespace cuhksz {

/**
  Samples the random integer according to [Poisson
  distribution](https://en.wikipedia.org/wiki/Poisson_distribution).
  It has parameter `lambda`, the "mean" or the expected value.

  PMF:<br/>
  \f$f(x)=\frac{\lambda^xe^{-\lambda}}{x!}\f$

  where \f$\lambda\f$ is the parameter `lambda`

  Usage:
  ```
  PoissonDistribution dist(5);
  dist.next();
  ```
**/
class PoissonDistribution : public Distribution<int> {
 public:
  /**
    Construct a Poisson distribution sampler with a new `Random` generator.
    @param lambda The expected value
  **/
  explicit PoissonDistribution(double lambda) : Distribution() { init(lambda); }

  /**
    Construct a Poisson distribution sampler with an existing `Random`
    generator.
    @param[in] r The `Random` generator to use.
    @param lambda The expected value
  **/
  PoissonDistribution(Random& r, double lambda) : Distribution(r) {
    init(lambda);
  }
  virtual ~PoissonDistribution() {}

  /**
    Sample an integer according to Poisson distribution.
  **/
  int next() override;

  /**
    Returns the parameter `lambda`.
  **/
  double lambda() { return lambda_; }

 private:
  double lambda_;
  double expLambda;

  void init(double lambda);
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_POISSONDISTRIBUTION
