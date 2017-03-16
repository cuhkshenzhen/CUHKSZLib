#include "random/random_functions.h"
#include <ctime>
#include <memory>
#include "random/Random.h"

namespace cuhksz {
cuhksz::Random& getInitializedGenerator();
int randomInt() {
  auto& randomGenerator = getInitializedGenerator();
  return randomGenerator.nextInt();
}

int randomInt(int min) {
  auto& randomGenerator = getInitializedGenerator();
  return randomGenerator.nextInt(min);
}
int randomInt(int min, int max) {
  auto& randomGenerator = getInitializedGenerator();
  return randomGenerator.nextInt(min, max);
}
double randomDouble(double min, double max) {
  auto& randomGenerator = getInitializedGenerator();
  return randomGenerator.nextDouble(min, max);
}
double randomDouble(double max) {
  auto& randomGenerator = getInitializedGenerator();
  return randomGenerator.nextDouble(max);
}
double randomBool() {
  auto& randomGenerator = getInitializedGenerator();
  return randomGenerator.nextBool();
}

cuhksz::Random& getInitializedGenerator() {
  static bool initialized;
  static std::unique_ptr<cuhksz::Random> randomGenerator;
  if (!initialized) {
    randomGenerator.reset(new cuhksz::Random(std::time(nullptr)));
    initialized = true;
  }
  return *randomGenerator;
}
}  // namespace cuhksz
