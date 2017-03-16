#include <cstdio>
#include "gtest/gtest.h"
#include "random.h"


TEST(RANDOM, naive) {
  ASSERT_TRUE(true);
}
// int main() {
//   // cuhksz::Random r;
//   int bucket[100];
//   for (int i = 0; i < 100; i++) bucket[i] = 0;
//   for (int i = 0; i < 100000; i++) {
//     bucket[cuhksz::randomInt(100)] += 1;
//   }
//   for (auto &i : bucket) std::printf("%d\n", i);
//   // std::printf("%d\n", cuhksz::randomInt());
// }
