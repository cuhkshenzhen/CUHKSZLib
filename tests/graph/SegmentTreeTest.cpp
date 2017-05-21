#include <vector>

#include "graph/SegmentTree.h"

#include "gtest/gtest.h"

TEST(SegmentTree, initialize) {
  std::vector<int> v;
  for (int i = 0; i < 4; i++) v.push_back(i);
  v[1] = 10;
  v[3] = -2;
  cuhksz::SegmentTree<int> T(v);
}

TEST(SegmentTree, queryMax) {
  std::vector<int> v;
  for (int i = 0; i < 4; i++) v.push_back(i);
  v[1] = 10;
  v[3] = -2;
  cuhksz::SegmentTree<int> T(v);
  EXPECT_EQ(T.queryMax(1, 2), 10);
  EXPECT_EQ(T.queryMax(1, 3), 10);
}

TEST(SegmentTree, queryMin) {
  std::vector<int> v;
  for (int i = 0; i < 4; i++) v.push_back(i);
  v[1] = 10;
  v[3] = -2;
  cuhksz::SegmentTree<int> T(v);
  EXPECT_EQ(T.queryMin(1, 2), 2);
  EXPECT_EQ(T.queryMin(1, 3), -2);
}

TEST(SegmentTree, querySum) {
  std::vector<int> v;
  for (int i = 0; i < 4; i++) v.push_back(i);
  v[1] = 10;
  v[3] = -2;
  cuhksz::SegmentTree<int> T(v);
  EXPECT_EQ(T.querySum(1, 2), 12);
  EXPECT_EQ(T.querySum(1, 3), 10);
}
