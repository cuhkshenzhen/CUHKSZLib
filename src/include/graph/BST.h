#ifndef CUHKSZ_GRAPH_BST
#define CUHKSZ_GRAPH_BST

namespace cuhksz {

class BSTNode {
public:
    BSTNode(int k, int v) : rank(k), val(v) {
        ch[0] = ch[1] = fa = nullptr;
    }

    int getVal() { return val; }
    int getRank() { return rank; }
    void setVal(int newVal) { val = newVal; }

    friend class BST;
private:
    BSTNode* ch[2];
    BSTNode* fa;
    int rank;
    int val;
};

class BST {
public:
    void insert(BSTNode* x);
    void erase(BSTNode* x);
    BSTNode* find(int k);
    BSTNode* pre(BSTNode* x);
    BSTNode* suf(BSTNode* x);

private:
    // c = 0 for left_rotate
    void rotate(BSTNode* x, int c);
    void splay(BSTNode* x);

    BSTNode* root;
};


}

#endif // CUHKSZ_GRAPH_DFS
