#include "random/Random.h"

#include <cstdlib>
#include <ctime>
#include <limits>

namespace cuhksz {

Random::Random(int seed) {
  randomGenerator.reset(new std::mt19937_64());
  randomGenerator->seed((std::uint64_t)seed);
}

int Random::nextInt(int min, int max) {
  return (int)((*randomGenerator)() % std::uint64_t(max - min)) + min;
}

int Random::nextInt() {
  int min = std::numeric_limits<int>::min();
  int max = std::numeric_limits<int>::max();
  return (int)((*randomGenerator)() % (std::uint64_t(max) + 1 - min)) + min;
}

int Random::nextInt(int max) { return nextInt(0, max); }

double Random::nextDouble(double min, double max) {
  auto rand_max = UINT64_MAX;
  return double((*randomGenerator)()) / rand_max * (max - min) + min;
}

double Random::nextDouble(double max) { return nextDouble(0.0, max); }

double Random::nextDouble() { return nextDouble(0.0, 1.0); }

bool Random::nextBool() { return nextInt(2); }

void Random::setSeed(int seed) { randomGenerator->seed(std::uint64_t(seed)); }

}  // namespace cuhksz
