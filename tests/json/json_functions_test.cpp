#include "json/json_functions.h"
#include "gtest/gtest.h"

TEST(JsonFunctions, jsonEscape) {
  ASSERT_EQ(cuhksz::jsonEscape("\\\"\\test\b\f\n\r\t"), "\\\\\\\"\\\\test\\b\\f\\n\\r\\t");
}
