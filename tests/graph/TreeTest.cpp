#include "graph/Tree.h"

#include "gtest/gtest.h"

#include <vector>

TEST(Node, initialize) {
  cuhksz::Node n(1);
  cuhksz::Node n1(2, 10);
}

TEST(Node, getter) {
  cuhksz::Node n(2, 10);
  EXPECT_EQ(n.getVal(), 10);
}

TEST(Node, setter) {
  cuhksz::Node f(1, 15);
  cuhksz::Node n(2, 10);
  n.setFa(&f);
  EXPECT_EQ(n.getFa(), &f);
  n.setHeight(3);
  EXPECT_EQ(n.getHeight(), 3);
}

TEST(Node, son) {
  cuhksz::Node f(1, 15);
  cuhksz::Node n(2, 10);
  f.addSon(&n);
  EXPECT_EQ(f.getSon()[0], &n);
}

TEST(Tree, root) {
  cuhksz::Node n(1, 10);
  cuhksz::Tree T;
  T.setRoot(&n);
  cuhksz::Node* root = T.getRoot();
  EXPECT_EQ(root->getHeight(), 0);
  EXPECT_EQ(root->getFa(), nullptr);
}

TEST(Tree, addNode) {
  cuhksz::Tree T;
  std::vector<cuhksz::Node*> nodes;
  for (int i = 0; i < 5; i++) nodes.push_back(new cuhksz::Node(i));
  T.setRoot(nodes[0]);
  T.addNode(nodes[1], nodes[0]);
  T.addNode(nodes[2], nodes[1]);
  T.addNode(nodes[3], nodes[0]);
  T.addNode(nodes[4], nodes[1]);
}

TEST(Tree, LCA) {
  cuhksz::Tree T;
  std::vector<cuhksz::Node*> nodes;
  for (int i = 0; i < 5; i++) nodes.push_back(new cuhksz::Node(i));
  T.setRoot(nodes[0]);
  T.addNode(nodes[1], nodes[0]);
  T.addNode(nodes[2], nodes[1]);
  T.addNode(nodes[3], nodes[0]);
  T.addNode(nodes[4], nodes[1]);

  EXPECT_EQ(nodes[2]->ancestor[0], nodes[1]);
  EXPECT_EQ(nodes[2]->ancestor[1], nodes[0]);
  EXPECT_EQ((int)nodes[2]->ancestor.size(), 2);
  EXPECT_EQ(nodes[2]->getHeight(), 2);

  EXPECT_EQ(nodes[3]->ancestor[0], nodes[0]);
  EXPECT_EQ((int)nodes[3]->ancestor.size(), 1);
  EXPECT_EQ(nodes[3]->getHeight(), 1);

  EXPECT_EQ(T.LCA(nodes[2], nodes[3]), nodes[0]);
  EXPECT_EQ(T.LCA(nodes[2], nodes[4]), nodes[1]);
  EXPECT_EQ(T.LCA(nodes[0], nodes[4]), nodes[0]);
}

TEST(Tree, getDistance) {
  cuhksz::Tree T;
  std::vector<cuhksz::Node*> nodes;
  for (int i = 0; i < 5; i++) nodes.push_back(new cuhksz::Node(i));
  T.setRoot(nodes[0]);
  T.addNode(nodes[1], nodes[0]);
  T.addNode(nodes[2], nodes[1]);
  T.addNode(nodes[3], nodes[0]);
  T.addNode(nodes[4], nodes[1]);

  EXPECT_EQ(T.getDistance(nodes[0], nodes[4]), 2);
  EXPECT_EQ(T.getDistance(nodes[2], nodes[4]), 2);
  EXPECT_EQ(T.getDistance(nodes[3], nodes[4]), 3);
}
