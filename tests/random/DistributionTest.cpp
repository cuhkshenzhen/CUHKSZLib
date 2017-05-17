#include <cmath>
#include "gtest/gtest.h"
#include "random/BernoulliDistribution.h"
#include "random/Distribution.h"

TEST(Distribution, setRandomGenerator) {
  cuhksz::BernoulliDistribution bernoulli;
  cuhksz::Distribution<bool>* dist = &bernoulli;
  cuhksz::Random r1(0);
  cuhksz::Random r2(0);
  dist->setRandomGenerator(r1);
  bool a = dist->next();
  dist->setRandomGenerator(r2);
  bool b = dist->next();
  EXPECT_EQ(a, b);
}
