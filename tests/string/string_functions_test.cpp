#include <cstdio>
#include "gtest/gtest.h"
#include "string/string_functions.h"

TEST(StringFunc, stringCast) {
  EXPECT_EQ(cuhksz::stringCast<int>("12345"), 12345);
}
