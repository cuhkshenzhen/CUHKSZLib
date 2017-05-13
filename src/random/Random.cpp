#include "random/Random.h"

#include <cstdlib>
#include <ctime>

#include "utils/error.h"

namespace cuhksz {

Random::Random(int seed) { randomGenerator.seed((std::uint64_t)seed); }

int Random::nextInt(int min, int max) {
  if (max <= min) error("`max` should be larger than `min`");
  return (int)(randomGenerator() % std::uint64_t(max - min)) + min;
}

int Random::nextInt() {
  return (int)(randomGenerator() % (std::uint64_t(intMax) + 1 - intMin)) +
         intMin;
}

int Random::nextInt(int max) {
  if (max <= 0) error("`max` should be positive");
  return nextInt(0, max);
}

double Random::nextDouble(double min, double max) {
  if (max < min) error("`max` should be larger than or equal to `min`");
  return (double)randomGenerator() / int64Max * (max - min) + min;
}

double Random::nextDouble(double max) {
  if (max < 0) error("`max` should non-negative");
  return nextDouble(0.0, max);
}

double Random::nextDouble() { return nextDouble(0.0, 1.0); }

bool Random::nextBool() { return nextInt(2); }

void Random::setSeed(int seed) { randomGenerator.seed(std::uint64_t(seed)); }

}  // namespace cuhksz
