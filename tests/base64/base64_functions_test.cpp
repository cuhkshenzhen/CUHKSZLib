#include "base64/base64_functions.h"
#include "gtest/gtest.h"

TEST(Base64FunctionsTest, base64Encode) {
  ASSERT_EQ(cuhksz::base64Encode("Base64 encode this string!"), "QmFzZTY0IGVuY29kZSB0aGlzIHN0cmluZyE=");
  ASSERT_EQ(cuhksz::base64Encode(""), "");
  ASSERT_EQ(cuhksz::base64Encode("any carnal pleasure"), "YW55IGNhcm5hbCBwbGVhc3VyZQ==");
}

TEST(Base64FunctionsTest, base64Decode) {
  ASSERT_EQ(cuhksz::base64Decode("QmFzZTY0IGVuY29kZSB0aGlzIHN0cmluZyE="), "Base64 encode this string!");
  ASSERT_EQ(cuhksz::base64Decode("QmFzZTY0IGVuY29kZSB0aGlzIHN0cmluZyE"), "Base64 encode this string!");
  ASSERT_EQ(cuhksz::base64Decode("===="), "");
  ASSERT_EQ(cuhksz::base64Decode("YW55IGNhcm5hbCBwbGVhc3VyZQ"), "any carnal pleasure");
}
