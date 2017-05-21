#include "graph/Vertex.h"
#include "graph/Edge.h"

#include "gtest/gtest.h"

TEST(Vertex, initialize) {
    cuhksz::Vertex v[10];
    v[0] = cuhksz::Vertex(3);
}

TEST(Vertex, getter) {
    cuhksz::Vertex v(3);
    EXPECT_EQ(v.getVal(), 3);

}

TEST(Vertex, setter) {
    cuhksz::Vertex v(3);
    v.setVal(5);
    EXPECT_EQ(v.getVal(), 5);
}

TEST(Vertex, compare) {
    cuhksz::Vertex v1(3), v2(5);
    EXPECT_TRUE(v1 < v2);
}

TEST(Vertex, addEdge) {
    cuhksz::Vertex v1(3);
    cuhksz::Vertex v2(5);
    v1.addEdge(v2);
    EXPECT_EQ(v1.outEdges.front()->getTo()->getVal(), 5);
    EXPECT_EQ(v2.inEdges.front()->getFrom()->getVal(), 3);
}
