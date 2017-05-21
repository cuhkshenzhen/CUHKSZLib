#include "graph/Edge.h"

#include "gtest/gtest.h"

TEST(Edge, initialize) {
  cuhksz::Vertex v1(3), v2(5);
  cuhksz::Edge e(&v1, &v2);
  cuhksz::Edge e1(&v2, &v1, 5);
  cuhksz::Edge e2(e);
}

TEST(Edge, getter) {
  cuhksz::Vertex v1(3), v2(5);
  cuhksz::Edge e(&v1, &v2, 8);
  EXPECT_EQ(e.getFrom(), &v1);
  EXPECT_EQ(e.getTo(), &v2);
  EXPECT_EQ(e.getVal(), 8);
}

TEST(Edge, setter) {
  cuhksz::Vertex v1(3), v2(5);
  cuhksz::Edge e(&v1, &v2, 8);
  e.setVal(12);
  EXPECT_EQ(e.getVal(), 12);
}

TEST(Edge, validation) {
  cuhksz::Vertex v1(3), v2(5);
  cuhksz::Edge e(&v1, &v2, 8);
  EXPECT_TRUE(e.isValid());
  e.setInvalid();
  EXPECT_TRUE(!e.isValid());
  e.setValid();
  EXPECT_TRUE(e.isValid());
}
