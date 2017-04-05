#ifndef CUHKSZ_RANDOM_POISSONDISTRIBUTION
#define CUHKSZ_RANDOM_POISSONDISTRIBUTION

#include "random/Distribution.h"

namespace cuhksz {
class PoissonDistribution : public Distribution<int> {
 public:
  explicit PoissonDistribution(double lambda) : Distribution() { init(lambda); }
  PoissonDistribution(Random& r, double lambda) : Distribution(r) {
    init(lambda);
  }
  virtual ~PoissonDistribution() {}

  int next() override;

  double lambda() { return lambda_; }

 private:
  double lambda_;
  double expLambda;

  void init(double lambda);
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_POISSONDISTRIBUTION
