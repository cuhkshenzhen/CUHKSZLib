#include "random/Random.h"

#include <cstdlib>
#include <ctime>

namespace cuhksz {

Random::Random(int seed) { randomGenerator.seed((std::uint64_t)seed); }

int Random::nextInt(int min, int max) {
  return (int)(randomGenerator() % std::uint64_t(max - min)) + min;
}

int Random::nextInt() {
  return (int)(randomGenerator() % (std::uint64_t(intMax) + 1 - intMin)) +
         intMin;
}

int Random::nextInt(int max) { return nextInt(0, max); }

double Random::nextDouble(double min, double max) {
  return double(randomGenerator()) / int64Max * (max - min) + min;
}

double Random::nextDouble(double max) { return nextDouble(0.0, max); }

double Random::nextDouble() { return nextDouble(0.0, 1.0); }

bool Random::nextBool() { return (bool) nextInt(2); }

void Random::setSeed(int seed) { randomGenerator.seed(std::uint64_t(seed)); }

}  // namespace cuhksz
