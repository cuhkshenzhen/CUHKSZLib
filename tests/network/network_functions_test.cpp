#include "network/network_functions.h"
#include "gtest/gtest.h"

TEST(NetworkFunctions, urlEncode) {
  ASSERT_EQ(cuhksz::urlEncode("http://google.com®"), "http%3A%2F%2Fgoogle.com%C2%AE");
}
