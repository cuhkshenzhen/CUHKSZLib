#ifndef CUHKSZ_RANDOM_UNIFORMDISTRIBUTION
#define CUHKSZ_RANDOM_UNIFORMDISTRIBUTION

#include "random/Distribution.h"
#include "random/Random.h"

namespace cuhksz {

/**
  Samples the random real numbers according to [continuous Uniform
  distribution](https://en.wikipedia.org/wiki/Uniform_distribution_(continuous)).
  It has parameters `min` and `max`. It produces real numbers in [`min`, `max`),
  i.e. includes `min` but excludes `max`.

  PDF:<br/>
  \f$f(x)=\frac{1}{\text{max}-\text{min}}\f$

  Usage:
  ```
  UniformDistribution dist(0, 1);
  dist.next();
  ```

  @sa Random::nextDouble(double min, double max)
  @sa randomDouble(double min, double max)
  @sa UniformIntDistribution
**/
class UniformDistribution : public Distribution<double> {
 public:
  /**
    Construct a continuous Uniform distribution sampler with a new `Random`
    generator.
    `min` is set to 0.
    @param max The max value (exclusive)
  **/
  explicit UniformDistribution(double max = 1) : Distribution() {
    init(0, max);
  }

  /**
    Construct a continuous Uniform distribution sampler with a new `Random`
    generator.
    @param min The min value (inclusive)
    @param max The max value (exclusive)
  **/
  UniformDistribution(double min, double max) : Distribution() {
    init(min, max);
  }

  /**
    Construct a continuous Uniform distribution sampler with an existing
    `Random` generator.
    `min` is set to 0.
    @param[in] r The `Random` generator to use.
    @param max The max value (exclusive)
  **/
  explicit UniformDistribution(Random& r, double max = 1) : Distribution(r) {
    init(0, max);
  }

  /**
    Construct a continuous Uniform distribution sampler with an existing
    `Random` generator.
    @param[in] r The `Random` generator to use.
    @param min The min value (inclusive)
    @param max The max value (exclusive)
  **/
  UniformDistribution(Random& r, double min, double max) : Distribution(r) {
    init(min, max);
  }

  virtual ~UniformDistribution() {}

  /**
    Sample a real number according to continuous Uniform distribution.
  **/
  double next() override;

  /**
    Returns the parameter `min`.
  **/
  double min() { return min_; }

  /**
    Returns the parameter `max`.
  **/
  double max() { return max_; }

 private:
  double min_;
  double max_;
  void init(double min, double max);
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_UNIFORMDISTRIBUTION
