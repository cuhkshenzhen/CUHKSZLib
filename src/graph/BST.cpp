#include "graph/BST.h"

namespace cuhksz {

void BST::rotate(BSTNode* x, int c) {
  BSTNode* y = x->fa;
  y->ch[!c] = x->ch[c];
  if (x->ch[c] != nullptr) x->ch[c]->fa = y;
  x->fa = y->fa;
  if (y->fa != nullptr) {
    if (y->fa->ch[0] == y)
      y->fa->ch[0] = x;
    else
      y->fa->ch[1] = x;
  }
  y->fa = x, x->ch[c] = y;
  if (y == root) root = x;
}

void BST::splay(BSTNode* x) {
  while (x->fa != nullptr) {
    if (x->fa->fa == nullptr) {
      if (x->fa->ch[0] == x)
        rotate(x, 1);
      else
        rotate(x, 0);
    } else {
      BSTNode* y = x->fa;
      BSTNode* z = y->fa;
      if (z->ch[0] == y) {
        if (y->ch[0] == x)
          rotate(y, 1), rotate(x, 1);
        else
          rotate(x, 0), rotate(x, 1);
      } else {
        if (y->ch[1] == x)
          rotate(y, 0), rotate(x, 0);
        else
          rotate(x, 1), rotate(x, 0);
      }
    }
  }
}

BSTNode* BST::pre(BSTNode* x) {
  BSTNode* cur = x->ch[0];
  if (cur == nullptr) return nullptr;
  while (cur->ch[1] != nullptr) cur = cur->ch[1];
  return cur;
}

BSTNode* BST::suf(BSTNode* x) {
  BSTNode* cur = x->ch[1];
  if (cur == nullptr) return nullptr;
  while (cur->ch[0] != nullptr) cur = cur->ch[0];
  return cur;
}

void BST::insert(BSTNode* x) {
  if (root == nullptr) {
    root = x;
    return;
  }

  BSTNode* cur = root;
  BSTNode* next;
  while (true) {
    if (x->rank < cur->rank) {
      next = cur->ch[0];
    } else {
      next = cur->ch[1];
    }
    if (next == nullptr) break;
    cur = next;
  }
  x->fa = cur;
  cur->ch[x->rank >= cur->rank] = x;
  splay(x);
}

void BST::erase(BSTNode* x) {
  splay(x);
  if (x->ch[0] == nullptr && x->ch[1] == nullptr) {
    root = nullptr;
  } else if (x->ch[0] == nullptr && x->ch[1] != nullptr) {
    root = x->ch[1];
    root->fa = nullptr;
  } else if (x->ch[0] != nullptr && x->ch[1] == nullptr) {
    root = x->ch[1];
    root->fa = nullptr;
  } else {
    root = pre(x);
    if (root->fa->ch[0] == root)
      root->fa->ch[0] = root->ch[0];
    else
      root->fa->ch[1] = root->ch[0];
    if (root->ch[0] != nullptr) root->ch[0]->fa = root->fa;
    root->fa = nullptr;
    root->ch[0] = x->ch[0];
    root->ch[1] = x->ch[1];
  }
}

BSTNode* BST::find(int k) {
  BSTNode* cur = root;
  while (cur != nullptr) {
    if (cur->rank == k) return cur;
    if (cur->rank < k)
      cur = cur->ch[1];
    else
      cur = cur->ch[0];
  }
  return nullptr;
}

}  // namespace cuhksz
