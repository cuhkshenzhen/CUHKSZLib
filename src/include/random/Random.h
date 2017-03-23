#ifndef CUHKSZ_RANDOM_RANDOM
#define CUHKSZ_RANDOM_RANDOM

#include <ctime>
#include <memory>
#include <random>

namespace cuhksz {
/**
  The `Random` class is the class used for general random number generating.
**/
class Random {
 public:
  /**
    Construct a `Random` class with current timestamps as random seed.
  **/
  Random() : Random((int)std::time(nullptr)) {}

  /**
    Construct a `Random` class with `seed` as random seed.
  **/
  explicit Random(int seed);

  /**
    Produce an `int` in the range [`min`, `max`), i.e. includes the `min` but
    excludes the `max`.
  **/
  int nextInt(int min, int max);
  int nextInt(int max);
  int nextInt();
  bool nextBool();
  double nextDouble(double min, double max);
  double nextDouble(double max);
  double nextDouble();
  void setSeed(int seed);

 private:
  std::unique_ptr<std::mt19937_64> randomGenerator;
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_RANDOM
