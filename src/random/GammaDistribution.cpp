#if defined(_MSC_VER) || defined(__MINGW32__)  // use e constant on windows
#define _USE_MATH_DEFINES
#endif

#include "random/GammaDistribution.h"

#include <cmath>

#include "utils/error.h"

namespace cuhksz {
void GammaDistribution::init(double k, double theta) {
  if (k <= 0 || theta <= 0) {
    error("Invalid parameter(s) for GammaDistribution");
  }
  k_ = k;
  theta_ = theta;
}

double GammaDistribution::next() {
  double sum_k = 0;
  for (int i = 0; i < (int)k_; i++) {
    double rnd = 1 - randomGenerator->nextDouble();  // uniform on (0, 1]
    sum_k += std::log(rnd);
  }
  double delta = k_ - std::floor(k_);

// disable gcc's warning for comparing with 0.0
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
  if (delta == 0.0) {  // integer k
    return theta_ * -sum_k;
#pragma GCC diagnostic pop
  } else {
    // Ahrens-Dieter acceptance–rejection method
    // https://en.wikipedia.org/wiki/Gamma_distribution#Generating_gamma-distributed_random_variables
    double u, v, w, ksi, ita;
    do {
      u = 1 - randomGenerator->nextDouble();
      v = 1 - randomGenerator->nextDouble();
      w = 1 - randomGenerator->nextDouble();
      if (u <= M_E / (M_E + delta)) {
        ksi = std::pow(v, 1 / delta);
        ita = w * std::pow(ksi, delta - 1);
      } else {
        ksi = 1 - std::log(v);
        ita = w * std::exp(-ksi);
      }
    } while (ita > std::pow(ksi, delta - 1) * std::exp(-ksi));
    return theta_ * (ksi - sum_k);
  }
}
}  // namespace cuhksz
