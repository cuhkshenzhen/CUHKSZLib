#include "random/Random.h"

#include <cstdlib>
#include <ctime>
#include <limits>

namespace cuhksz {
Random::Random() : Random(static_cast<int>(std::time(nullptr))) {}

Random::Random(int seed) {
  randomGenerator.reset(new std::mt19937_64());
  randomGenerator->seed(static_cast<std::uint64_t>(seed));
}

int Random::nextInt(int min, int max) {
  return ((*randomGenerator)() % static_cast<std::uint64_t>(max - min)) + min;
}

int Random::nextInt() {
  return nextInt(std::numeric_limits<int>::min(),
                 std::numeric_limits<int>::max());
}

int Random::nextInt(int max) { return nextInt(0, max); }

double Random::nextDouble(double min, double max) {
  auto rand_max = UINT64_MAX;
  return static_cast<double>((*randomGenerator)()) / rand_max * (max - min) +
         min;
}

double Random::nextDouble(double max) { return nextDouble(0.0, max); }

bool Random::nextBool() { return nextInt(2); }

void Random::setSeed(int seed) {
  randomGenerator->seed(static_cast<std::uint64_t>(seed));
}

}  // namespace cuhksz
