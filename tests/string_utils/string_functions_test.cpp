#include <cstdio>
#include "gtest/gtest.h"
#include "string_utils/string_functions.h"

TEST(StringFunc, stringCast) {
  EXPECT_EQ(cuhksz::stringCast<int>("12345"), 12345);
}
