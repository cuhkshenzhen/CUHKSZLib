#ifndef CUHKSZ_GRAPH_TREE
#define CUHKSZ_GRAPH_TREE

#include <vector>

namespace cuhksz {

class Node {
public:
    Node(int id) : Node(id, 0) {}
    Node(int id, int val);

    ~Node();

    int getVal() { return val; }
    Node* getFa() { return fa; }
    std::vector<Node*> getSon() { return son; }
    void setFa(Node* newFa) { fa = newFa; }
    void addSon(Node* newSon) { son.push_back(newSon); }
    int getHeight() { return height; }
    void setHeight(int h) { height = h; }
    Node* getAncestor(int level);
    int getDegree() { return son.size(); }
    int getID() { return id; }

    std::vector<Node*> ancestor;    // power 2 ancestor

private:
    Node* fa;
    std::vector<Node*> son;
    int id;
    int val;
    int height;
};

class Tree {
public:
    void setRoot(Node* newRoot);
    void addNode(Node* node, Node* fa);

    Node* LCA(Node* x, Node* y);
    int getDistance(Node* x, Node* y);

private:
    Node* root;
    std::vector<Node*> nodes;
};



}

#endif // CUHKSZ_GRAPH_TREE
