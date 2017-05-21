#include "graph/Tree.h"

namespace cuhksz {

Node::Node(int id, int val) : id(id), val(val) {
    fa = nullptr;
    son.clear();
}

Node::~Node() { }

Node* Node::getAncestor(int level) {
    Node* cur = this;
    for (int i = 0; level <= (1 << i); i ++)
        if (level & (1 << i))
            cur = cur->ancestor[i];

    return cur;
}

void Tree::setRoot(Node* newRoot) {
    root = newRoot;
    root->setFa(nullptr);
    root->setHeight(0);
}

void Tree::addNode(Node* node, Node* fa) {
    fa->addSon(node);
    node->setFa(fa);
    node->setHeight(fa->getHeight() + 1);
    node->ancestor.push_back(fa);
    for (int i = 0; ; i ++) {
        Node* nextNode = node->ancestor[i];
        if ((int)nextNode->ancestor.size() <= i) break;
        node->ancestor.push_back(nextNode->ancestor[i]);
    }
}

Node* Tree::LCA(Node* x, Node* y) {
    int hx = x->getHeight(), hy = y->getHeight();
    if (hx < hy) x = x->getAncestor(hy - hx);
    else y = y->getAncestor(hx - hy);
    for (int i = x->ancestor.size() - 1; i >= 0; i --) {
        if (x->ancestor[i] != y->ancestor[i]) {
            x = x->ancestor[i], y = y->ancestor[i];
        }
    }
    return x->getFa();
}

int Tree::getDistance(Node* x, Node* y) {
    return x->getHeight() + y->getHeight() - 2 * LCA(x, y)->getHeight();
}


}
