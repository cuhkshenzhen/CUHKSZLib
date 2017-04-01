#ifndef CUHKSZ_RANDOM_RANDOM
#define CUHKSZ_RANDOM_RANDOM

#include <ctime>
#include <limits>
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
    Produce a random `int` in the range [`min`, `max`), i.e. includes the `min`
    but excludes the `max`.
  **/
  int nextInt(int min, int max);

  /**
    Produce a random `int` in the range [0, `max`), i.e. includes 0 but
    excludes `max`.
  **/
  int nextInt(int max);

  /**
    Produce a random `int` out of all possible `int` values.
  **/
  int nextInt();

  /**
    Produce a random `bool` with the probability of 0.5 `true` and 0.5 `false`.
  **/
  bool nextBool();

  /**
    Produce a random `double` in the range [`min`, `max`).
  **/
  double nextDouble(double min, double max);

  /**
    Produce a random `double` in the range [0, `max`).
  **/
  double nextDouble(double max);

  /**
    Produce a random `double` in the range [0, 1).
  **/
  double nextDouble();

  /**
    Set the new `seed` for the random generator.
  **/
  void setSeed(int seed);

 private:
  std::mt19937_64 randomGenerator;
  static const auto intMax = std::numeric_limits<int>::max();
  static const auto intMin = std::numeric_limits<int>::min();
  static const auto int64Max = std::numeric_limits<std::uint64_t>::max();
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_RANDOM
