#include "gtest/gtest.h"
#include "random.h"

TEST(UniformDistribution, integration) {
  cuhksz::UniformDistribution ud;
  printf("%f\n", ud.next());
  cuhksz::Random rnd;
  cuhksz::UniformDistribution ud2(rnd);
  printf("%f\n", ud2.next());
}
