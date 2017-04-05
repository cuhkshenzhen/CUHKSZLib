#ifndef CUHKSZ_RANDOM_DISTRIBUTION
#define CUHKSZ_RANDOM_DISTRIBUTION
#include "random/Random.h"

namespace cuhksz {
template <typename ResultType>
class Distribution {
 public:
  Distribution() : Distribution(*(new Random())) { newedRandom = true; }

  explicit Distribution(Random& random) : randomGenerator(&random) {
    newedRandom = false;
  }
  virtual ~Distribution() {
    if (newedRandom) delete randomGenerator;
  }
  virtual ResultType next() = 0;

  void setRandomGenerator(Random& random) {
    if (newedRandom) delete randomGenerator;
    newedRandom = false;
    randomGenerator = &random;
  }

 protected:
  Random* randomGenerator = nullptr;

 private:
  bool newedRandom;
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_DISTRIBUTION
