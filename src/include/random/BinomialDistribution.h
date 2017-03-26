#ifndef CUHKSZ_RANDOM_BINOMIALDISTRIBUTION
#define CUHKSZ_RANDOM_BINOMIALDISTRIBUTION

#include "random/Distribution.h"
namespace cuhksz {
class BinomialDistribution : public Distribution<int> {
 public:
  explicit BinomialDistribution(int n, double p = 0.5) : Distribution() {
    init(n, p);
  }
  BinomialDistribution(Random& r, int n, double p = 0.5) : Distribution(r) {
    init(n, p);
  }
  virtual ~BinomialDistribution() {}

  int next() override;

  int n() { return n_; }
  double p() { return p_; }

 private:
  int n_;
  double p_;
  void init(int n, double p);
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_BINOMIALDISTRIBUTION
