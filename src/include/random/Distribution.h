#ifndef RANDOM_DISTRIBUTION
#define RANDOM_DISTRIBUTION
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
  
  virtual void setRandomGenerator(Random& random) {
    if (newedRandom) delete randomGenerator;
    newedRandom = false;
    randomGenerator = &random;
  }

 protected:
  bool newedRandom;
  Random* randomGenerator;
};
}  // namespace cuhksz

#endif  // RANDOM_DISTRIBUTION
