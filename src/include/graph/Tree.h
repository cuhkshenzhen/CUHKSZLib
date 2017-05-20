#ifndef CUHKSZ_GRAPH_TREE
#define CUHKSZ_GRAPH_TREE

#include <vector>

namespace cuhksz {

class Node {
public:
    Node();
    ~Node();

    void 
private:
    Node* fa;
    std::vector<Node*> son;
    int val;
    int id;
};

class Tree {

};



}

#endif // CUHKSZ_GRAPH_TREE
