#ifndef CUHKSZ_RANDOM_UNIFORMINTDISTRIBUTION
#define CUHKSZ_RANDOM_UNIFORMINTDISTRIBUTION

#include "random/Distribution.h"
#include "random/Random.h"

namespace cuhksz {

/**
  Samples the random integer according to [discrete Uniform
  distribution](https://en.wikipedia.org/wiki/Discrete_uniform_distribution).
  It has parameters `min` and `max`. It produces integer in [`min`, `max`),
  i.e. includes `min` but excludes `max`.

  PMF:<br/>
  \f$f(x)=\frac{1}{\text{max}-\text{min}}\f$

  Usage:
  ```
  UniformIntDistribution dist(0, 10);
  dist.next();
  ```

  @sa Random::nextInt(int min, int max)
  @sa randomInt(int min, int max)
  @sa UniformDistribution
**/
class UniformIntDistribution : public Distribution<int> {
 public:
  /**
    Construct a discrete Uniform distribution sampler with a new `Random`
    generator.
    `min` is set to 0.
    @param max The max value (exclusive)
  **/
  explicit UniformIntDistribution(int max) : Distribution() { init(0, max); }

  /**
    Construct a discrete Uniform distribution sampler with a new `Random`
    generator.
    @param min The min value (inclusive)
    @param max The max value (exclusive)
  **/
  UniformIntDistribution(int min, int max) : Distribution() { init(min, max); }

  /**
    Construct a discrete Uniform distribution sampler with an existing
    `Random` generator.
    `min` is set to 0.
    @param[in] r The `Random` generator to use.
    @param max The max value (exclusive)
  **/
  UniformIntDistribution(Random& r, int max) : Distribution(r) { init(0, max); }

  /**
    Construct a discrete Uniform distribution sampler with an existing
    `Random` generator.
    @param[in] r The `Random` generator to use.
    @param min The min value (inclusive)
    @param max The max value (exclusive)
  **/
  UniformIntDistribution(Random& r, int min, int max) : Distribution(r) {
    init(min, max);
  }

  virtual ~UniformIntDistribution() {}

  /**
    Sample an integer according to discrete Uniform distribution.
  **/
  int next() override;

  /**
    Returns the parameter `min`.
  **/
  int min() { return min_; }

  /**
    Returns the parameter `max`.
  **/
  int max() { return max_; }

 private:
  int min_;
  int max_;
  void init(int min, int max);
};
}  // namespace cuhksz

#endif  // RANDOM_UNIFORMINTDISTRIBUTION
