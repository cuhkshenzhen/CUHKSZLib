#include "random.h"
#include <iostream>
using namespace cuhksz;

void printFlip(bool flip);

int main() {
  // the last consecutive 3 flips: f1 f2 f3. f3 is the latest one.
  bool f1, f2, f3;
  // false for tails and true for heads
  f1 = f2 = f3 = false;
  int total_flips = 0;
  while (!(f1 && f2 && f3)) {
    total_flips++;
    f1 = f2;
    f2 = f3;
    f3 = randomBool();
    printFlip(f3);
  }
  std::cout << "It took " << total_flips << " flips to get 3 consecutive heads."
            << std::endl;
}

void printFlip(bool flip) {
  if (flip) {
    std::cout << "heads" << std::endl;
  } else {
    std::cout << "tails" << std::endl;
  }
}
