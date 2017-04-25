#ifndef CUHKSZ_RANDOM_BERNOULLIDISTRIBUTION
#define CUHKSZ_RANDOM_BERNOULLIDISTRIBUTION

#include "random/Distribution.h"
namespace cuhksz {
/**
  Samples the random boolean value according to [Bernoulli
  distribution](https://en.wikipedia.org/wiki/Bernoulli_distribution).
  It has parameter `p` as the probability of success.

  PMF:<br/>
  \f$p\f$ for `true`<br/>
  \f$1-p\f$ for `false`

  Usage:
  ```
  BernoulliDistribution dist(0.2);
  dist.next();
  ```
**/
class BernoulliDistribution : public Distribution<bool> {
 public:
  /**
    Construct a Bernoulli distribution sampler with a new `Random` generator.
    @param p The probability of success.
  **/
  explicit BernoulliDistribution(double p = 0.5) : Distribution() { init(p); }

  /**
    Construct a Bernoulli distribution sampler with an existing `Random`
    generator.
    @param[in] r The `Random` generator to use.
    @param p The probability of success.
  **/
  explicit BernoulliDistribution(Random& r, double p = 0.5) : Distribution(r) {
    init(p);
  }

  virtual ~BernoulliDistribution() {}

  /**
    Sample a boolean value according to Bernoulli distribution.
  **/
  bool next() override;

  /**
    Returns the parameter `p`.
  **/
  double p() { return p_; }

 private:
  double p_;
  void init(double p);
};
}  // namespace cuhksz
#endif  // CUHKSZ_RANDOM_BERNOULLIDISTRIBUTION
