#ifndef CUHKSZ_RANDOM_NEGATIVEBINOMIALDISTRIBUTION
#define CUHKSZ_RANDOM_NEGATIVEBINOMIALDISTRIBUTION

#include <memory>
#include "random/Distribution.h"

namespace cuhksz {

/**
  Samples the random integer according to [Negative binomial
  distribution](https://en.wikipedia.org/wiki/Negative_binomial_distribution).
  It has parameters `r` as the number of successes, the and `p` as the
  probability of success. And the sampled integer means the number of failures
  before achive `r` successes.

  PMF:<br/>
  \f$f(x)={x+r-1 \choose r-1}p^r(1-p)^x\f$

  Usage:
  ```
  NegativeBinomialDistribution dist(2, 0.5);
  dist.next();
  ```
**/
class NegativeBinomialDistribution : public Distribution<int> {
 public:
  /**
    Construct a Negative binomial distribution sampler with a new `Random`
    generator.
    @param r The number of successes
    @param p The probability of success
  **/
  explicit NegativeBinomialDistribution(int r, double p = 0.5)
      : Distribution() {
    init(r, p);
  }

  /**
    Construct a Negative binomial distribution sampler with an existing `Random`
    generator.
    @param[in] rnd The `Random` generator to use.
    @param r The number of successes
    @param p The probability of success
  **/
  NegativeBinomialDistribution(Random& rnd, int r, double p = 0.5)
      : Distribution(rnd) {
    init(r, p);
  }

  virtual ~NegativeBinomialDistribution() {}

  /**
    Sample an integer according to Negative binomial distribution.
  **/
  int next() override;

  /**
    Returns the parameter `r`.
  **/
  int r() { return r_; }

  /**
    Returns the parameter `p`.
  **/
  double p() { return p_; }

 private:
  int r_;
  double p_;

  double pPowr;

  void init(int r, double p);
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_NEGATIVEBINOMIALDISTRIBUTION
