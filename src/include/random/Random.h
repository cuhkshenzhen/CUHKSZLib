#ifndef CUHKSZ_RANDOM_RANDOM
#define CUHKSZ_RANDOM_RANDOM

#include <memory>
#include <random>

namespace cuhksz {
class Random {
 public:
  Random() : Random((int)std::time(nullptr)) {}
  explicit Random(int);
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
