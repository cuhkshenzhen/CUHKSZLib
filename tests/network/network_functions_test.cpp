#include "network/network_functions.h"
#include "gtest/gtest.h"

TEST(NetworkFunctions, urlEncode) {
  ASSERT_EQ(cuhksz::urlEncode(u8"http://google.com®"), "http%3A%2F%2Fgoogle.com%C2%AE");
  ASSERT_EQ(cuhksz::urlEncode(u8"Hello Günt+er"), "Hello%20G%C3%BCnt%2Ber");
}
