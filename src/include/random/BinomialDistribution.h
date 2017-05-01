#ifndef CUHKSZ_RANDOM_BINOMIALDISTRIBUTION
#define CUHKSZ_RANDOM_BINOMIALDISTRIBUTION

#include <memory>
#include "random/Distribution.h"

namespace cuhksz {
/**
  Samples the random integer according to [Binomial
  distribution](https://en.wikipedia.org/wiki/Binomial_distribution).
  It has parameters `n` as the number of Bernoulli trials and `p` as the
  probability of success.

  PMF:<br/>
  \f$f(x) = {n \choose x}p^x(1-p)^{n-x}\f$

  Usage:
  ```
  BinomialDistribution dist(5, 0.2);
  dist.next();
  ```
**/
class BinomialDistribution : public Distribution<int> {
 public:
  /**
    Construct a Binomial distribution sampler with a new `Random` generator.
    @param n The number of Bernoulli trials
    @param p The probability of success
  **/
  explicit BinomialDistribution(int n, double p = 0.5) : Distribution() {
    init(n, p);
  }

  /**
    Construct a Binomial distribution sampler with an existing `Random`
    generator.
    @param[in] r The `Random` generator to use.
    @param n The number of Bernoulli trials
    @param p The probability of success
  **/
  BinomialDistribution(Random& r, int n, double p = 0.5) : Distribution(r) {
    init(n, p);
  }

  virtual ~BinomialDistribution() {}

  /**
    Sample an integer according to Binomial distribution.
  **/
  int next() override;

  /**
    Returns the parameter `n`.
  **/
  int n() { return n_; }

  /**
    Returns the parameter `p`.
  **/
  double p() { return p_; }

 private:
  int n_;
  double p_;
  std::unique_ptr<double[]> lookup_table = nullptr;

  void init(int n, double p);
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_BINOMIALDISTRIBUTION
