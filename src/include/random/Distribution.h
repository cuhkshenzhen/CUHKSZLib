#ifndef CUHKSZ_RANDOM_DISTRIBUTION
#define CUHKSZ_RANDOM_DISTRIBUTION
#include "random/Random.h"

namespace cuhksz {
/**
  The base class of all random distributions. Note that this is a class
  template, so only random distributions with the same type share the same base
  class. Also, it is a abstract class, so you cannot have an object of it.
  You can write your own distribution class by inhere this class.

  Usage:
  ```
  Distribution<bool>* dist;
  BernoulliDistribution bernoulli;
  dist = &bernoulli;
  dist->next();
  ```
**/
template <typename ResultType>
class Distribution {
 public:
  /**
    Construct a distribution with a new `Random` generator. All subclasses
    should delegate to this constructor to get a new `Random` object.
  **/
  Distribution() : Distribution(*(new Random())) { newedRandom = true; }

  /**
    Construct a distribution with an existing `Random` generator.
    All subclasses should delegate to this constructor to use an existing
    `Random` object.
    @param[in] random The `Random` generator to use.
  **/
  explicit Distribution(Random& random) : randomGenerator(&random) {
    newedRandom = false;
  }

  virtual ~Distribution() {
    if (newedRandom) delete randomGenerator;
  }

  /**
    Returns the next sampled value according to the distribution.
  **/
  virtual ResultType next() = 0;

  /**
    Set the underlying Random generator to `random`.

    __Do not override(overwrite) it!.__

    @param[in] random New `Random` generator to use.
  **/
  void setRandomGenerator(Random& random) {
    if (newedRandom) delete randomGenerator;
    newedRandom = false;
    randomGenerator = &random;
  }

  /// \cond NODOC
  Distribution(Distribution&) = delete;
  Distribution(Distribution&&) = delete;
  Distribution& operator=(Distribution&) = delete;
  Distribution& operator=(Distribution&&) = delete;
  /// \endcond

 protected:
  /**
    The underlying `Random` generator. Subclasses should call the methods of
    `randomGenerator` to generate sampling values to get pseudorandom numbers.
  **/
  Random* randomGenerator = nullptr;

 private:
  bool newedRandom;
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_DISTRIBUTION
