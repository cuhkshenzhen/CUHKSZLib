#ifndef CUHKSZ_RANDOM_RANDOM
#define CUHKSZ_RANDOM_RANDOM

#include <ctime>
#include <limits>
#include <memory>
#include <random>

namespace cuhksz {
/**
  The `Random` class is used for general random number generating.
  It has some fundamental methods to generate random integers, real numbers
  (float point numbers) and boolean values. The random seed can also be
  customized to generate pseudorandom numbers of the same sequence.
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

    See also randomInt(int min, int max)
  **/
  int nextInt(int min, int max);

  /**
    Produce a random `int` in the range [0, `max`), i.e. includes 0 but
    excludes `max`.

    See also: randomInt(int max)
  **/
  int nextInt(int max);

  /**
    Produce a random `int` out of all possible `int` values.

    See also: randomInt()
  **/
  int nextInt();

  /**
    Produce a random `bool` with the probability of 0.5 `true` and 0.5 `false`.

    See also: randomBool()
  **/
  bool nextBool();

  /**
    Produce a random `double` in the range [`min`, `max`).

    See also: randomDouble(double min, double max)
  **/
  double nextDouble(double min, double max);

  /**
    Produce a random `double` in the range [0, `max`).

    See also: randomDouble(double max)
  **/
  double nextDouble(double max);

  /**
    Produce a random `double` in the range [0, 1).

    See also: randomDouble()
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
