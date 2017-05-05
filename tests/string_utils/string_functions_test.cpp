#include <cstdio>
#include "gtest/gtest.h"
#include "string_utils/StringCast.h"

TEST(StringFunc, stringCast) {
  EXPECT_EQ((int)cuhksz::stringCast<int>("12345"), 12345);
}
