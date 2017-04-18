#include "random/StudentTDistribution.h"
#include <cmath>
#include "random/ChiSquaredDistribution.h"
#include "random/NormalDistribution.h"

namespace cuhksz {
void StudentTDistribution::init(double r) {
  if (r <= 0) {
    exit(1);  // TODO: error here
  }
  r_ = r;
}

double StudentTDistribution::next() {
  NormalDistribution normal(*randomGenerator);
  ChiSquaredDistribution chi2(*randomGenerator, r_);
  return normal.next() * std::sqrt(r_ / chi2.next());
}
}  // namespace cuhksz
