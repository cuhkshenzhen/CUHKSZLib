#ifndef CUHKSZ_RANDOM_NORMALDISTRIBUTION
#define CUHKSZ_RANDOM_NORMALDISTRIBUTION

#include "random/Distribution.h"
namespace cuhksz {
class NormalDistribution : public Distribution<double> {
 public:
  explicit NormalDistribution(double mean = 0, double stddev = 1)
      : Distribution() {
    init(mean, stddev);
  }
  explicit NormalDistribution(Random& r, double mean = 0, double stddev = 1)
      : Distribution(r) {
    init(mean, stddev);
  }
  virtual ~NormalDistribution() {}

  double next() override;

  double mean() { return mean_; }
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
