#include <cstdio>
#include <vector>
#include <zip.h>
#include "gtest/gtest.h"
#include "zip/zip_functions.h"

TEST(Zip, zip) {
  std::vector<int> a = {1, 2, 3, 4};
  std::vector<int> b = {5, 6, 7, 8};
  std::vector<int> c = {9, 10, 11};
  std::vector<std::vector<int>> result = {{1, 5, 9}, {2, 6, 10}, {3, 7, 11}};
  auto origin = cuhksz::zip(a, b, c);
  EXPECT_EQ(origin, result);
}
