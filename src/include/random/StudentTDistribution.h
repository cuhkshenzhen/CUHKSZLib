#ifndef CUHKSZ_RANDOM_STUDENTTDISTRIBUTION
#define CUHKSZ_RANDOM_STUDENTTDISTRIBUTION

#include "random/Distribution.h"
namespace cuhksz {
class StudentTDistribution : public Distribution<double> {
 public:
  explicit StudentTDistribution(double r) : Distribution() { init(r); }
  explicit StudentTDistribution(Random& rnd, double r) : Distribution(rnd) {
    init(r);
  }
  virtual ~StudentTDistribution() {}

  double next() override;

 private:
  double r_;
  void init(double r);
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_STUDENTTDISTRIBUTION
