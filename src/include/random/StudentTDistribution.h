#ifndef CUHKSZ_RANDOM_STUDENTTDISTRIBUTION
#define CUHKSZ_RANDOM_STUDENTTDISTRIBUTION

#include "random/Distribution.h"
namespace cuhksz {

/**
  Samples the random real numbers according to [Student's
  t-distribution](https://en.wikipedia.org/wiki/Student%27s_t-distribution).
  It has parameter `r`, the degrees of freedom.

  PDF:<br/>
  \f$f(x)=\frac{\Gamma\left(\frac{r+1}{2}\right)}{\sqrt{r\pi}\Gamma(r/2)}
  \left(1+\frac{x^2}{r}\right)^{-\frac{r+1}{2}}\f$

  Usage:
  ```
  StudentTDistribution dist(1);
  dist.next();
  ```
**/
class StudentTDistribution : public Distribution<double> {
 public:
  /**
    Construct a Student's t-distribution sampler with a new `Random` generator.
    @param r The degrees of freedom
  **/
  explicit StudentTDistribution(double r) : Distribution() { init(r); }

  /**
    Construct a Student's t-distribution sampler with an existing `Random`
    generator.
    @param[in] rnd The `Random` generator to use.
    @param r The degrees of freedom
  **/
  explicit StudentTDistribution(Random& rnd, double r) : Distribution(rnd) {
    init(r);
  }

  virtual ~StudentTDistribution() {}

  /**
    Sample a real number according to Student's t-distribution.
  **/
  double next() override;

  /**
    Returns the parameter `r`.
  **/
  double r() { return r_; }

 private:
  double r_;
  void init(double r);
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_STUDENTTDISTRIBUTION
