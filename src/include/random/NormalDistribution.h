#ifndef CUHKSZ_RANDOM_NORMALDISTRIBUTION
#define CUHKSZ_RANDOM_NORMALDISTRIBUTION

#include "random/Distribution.h"
namespace cuhksz {

/**
  Samples the random real numbers according to [Normal
  distribution](https://en.wikipedia.org/wiki/Normal_distribution).
  It has parameters `mean` and `stddev` (standard deviation).

  PDF:<br/>
  \f$f(x)=\frac{1}{\sqrt{2\pi\sigma^2}}\exp\left(-\frac{(x-\mu)^2}{2\sigma^2}\right)\f$

  where \f$\mu\f$ is the `mean` parameter, and \f$\sigma\f$ is the `stddev`
  parameter.

  Usage:
  ```
  NormalDistribution dist();  // standard normal distribution
  dist.next();
  ```
**/
class NormalDistribution : public Distribution<double> {
 public:
  /**
    Construct a Normal distribution sampler with a new `Random` generator.
    @param mean The mean
    @param stddev The standard deviation
  **/
  explicit NormalDistribution(double mean = 0, double stddev = 1)
      : Distribution() {
    init(mean, stddev);
  }

  /**
    Construct a Gamma distribution sampler with an existing `Random` generator.
    @param[in] r The `Random` generator to use.
    @param mean The mean
    @param stddev The standard deviation
  **/
  explicit NormalDistribution(Random& r, double mean = 0, double stddev = 1)
      : Distribution(r) {
    init(mean, stddev);
  }

  virtual ~NormalDistribution() {}

  /**
    Sample a real number according to Normal distribution.
  **/
  double next() override;

  /**
    Returns the parameter `mean`.
  **/
  double mean() { return mean_; }

  /**
    Returns the parameter `stddev`.
  **/
  double stddev() { return stddev_; }

 private:
  double mean_;
  double stddev_;
  double spareResult;
  bool hasSpare = false;
  void init(double mean, double stddev);
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_NORMALDISTRIBUTION
