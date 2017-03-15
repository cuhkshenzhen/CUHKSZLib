#ifndef CUHKSZ_RANDOM_RANDOM
#define CUHKSZ_RANDOM_RANDOM

#include <cstdint>
#include <memory>
#include <random>

namespace cuhksz {
class Random {
 public:
  Random();
  explicit Random(int);
  int nextInt(int min, int max);
  int nextInt(int max);
  int nextInt();
  bool nextBool();
  double nextDouble(double min, double max);
  double nextDouble(double max);
  void setSeed(int seed);

 private:
  std::unique_ptr<std::mt19937_64> randomGenerator;
  explicit Random(std::uint64_t);
};
}  // namespace cuhksz

#endif  // CUHKSZ_RANDOM_RANDOM
