#include "graph/BST.h"

#include "gtest/gtest.h"

#include <vector>

TEST(BSTNode, initialize) { cuhksz::BSTNode n(1, 2); }

TEST(BSTNode, getter) {
  cuhksz::BSTNode n(1, 2);
  EXPECT_EQ(n.getVal(), 2);
  EXPECT_EQ(n.getRank(), 1);
}

TEST(BSTNode, setter) {
  cuhksz::BSTNode n(1, 2);
  n.setVal(3);
  EXPECT_EQ(n.getVal(), 3);
}

TEST(BST, insert) {
  cuhksz::BST T;
  std::vector<cuhksz::BSTNode*> nodes;
  for (int i = 0; i < 4; i++) {
    nodes.push_back(new cuhksz::BSTNode(i, i));
    T.insert(nodes[i]);
  }
}

TEST(BST, erase) {
  cuhksz::BST T;
  std::vector<cuhksz::BSTNode*> nodes;
  for (int i = 0; i < 4; i++) {
    nodes.push_back(new cuhksz::BSTNode(i, i));
    T.insert(nodes[i]);
  }
  T.erase(nodes[0]);
  T.erase(nodes[2]);
}

TEST(BST, find) {
  cuhksz::BST T;
  std::vector<cuhksz::BSTNode*> nodes;
  for (int i = 0; i < 4; i++) {
    nodes.push_back(new cuhksz::BSTNode(i, i));
    T.insert(nodes[i]);
  }
  EXPECT_EQ(T.find(3), nodes[3]);
}
