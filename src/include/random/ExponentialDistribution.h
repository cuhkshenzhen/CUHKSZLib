#ifndef CUHKSZ_RANDOM_EXPONENTIALDISTRIBUTION
#define CUHKSZ_RANDOM_EXPONENTIALDISTRIBUTION

#include "random/Distribution.h"
namespace cuhksz {
class ExponentialDistribution : public Distribution<double> {
 public:
  explicit ExponentialDistribution(double lambda) : Distribution() {
    init(lambda);
  }
  ExponentialDistribution(Random& r, double lambda) : Distribution(r) {
    init(lambda);
  }
  virtual ~ExponentialDistribution() {}

  double next() override;

  double lambda() { return lambda_; }

 private:
  double lambda_;

  void init(double lambda);
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_EXPONENTIALDISTRIBUTION
