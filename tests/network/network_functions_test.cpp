#include "network/network_functions.h"
#include "gtest/gtest.h"

TEST(NetworkFunctions, urlEncode) {
  ASSERT_EQ(cuhksz::urlEncode("http://google.com®"),
            "http%3A%2F%2Fgoogle.com%C2%AE");
  ASSERT_EQ(cuhksz::urlEncode("Hello Günt+er"), "Hello%20G%C3%BCnt%2Ber");
}

TEST(NetworkFunctions, urlDncode) {
  ASSERT_EQ(cuhksz::urlDecode("http%3A%2F%2Fgoogle.com%C2%AE"),
            "http://google.com®");
  ASSERT_EQ(cuhksz::urlDecode("Hello%20G%C3%BCnt%2Ber"), "Hello Günt+er");
}
