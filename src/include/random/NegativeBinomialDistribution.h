#ifndef CUHKSZ_RANDOM_NEGATIVEBINOMIALDISTRIBUTION
#define CUHKSZ_RANDOM_NEGATIVEBINOMIALDISTRIBUTION

#include <memory>
#include "random/Distribution.h"

namespace cuhksz {
class NegativeBinomialDistribution : public Distribution<int> {
 public:
  explicit NegativeBinomialDistribution(int r, double p = 0.5)
      : Distribution() {
    init(r, p);
  }
  NegativeBinomialDistribution(Random& rnd, int r, double p = 0.5)
      : Distribution(rnd) {
    init(r, p);
  }
  virtual ~NegativeBinomialDistribution() {}

  int next() override;

  int r() { return r_; }
  double p() { return p_; }

 private:
  int r_;
  double p_;

  double pPowr;
  double constant;

  void init(int r, double p);
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_NEGATIVEBINOMIALDISTRIBUTION
