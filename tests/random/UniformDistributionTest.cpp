#include "gtest/gtest.h"
#include "random.h"

TEST(UniformDistribution, integration) {
  cuhksz::UniformDistribution ud;
  cuhksz::Random rnd;
  cuhksz::UniformDistribution ud2(rnd);
  ud.next();
  ud2.next();
}
