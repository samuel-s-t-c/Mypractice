#ifndef PRACTICEH
#define PRACTICEH

#include <iostream>
#include <string>

class TreeNode {
public:
  TreeNode() : value(std::string()), count(1), left(nullptr), right(nullptr), refCnt(new int(1)){}
  TreeNode(const TreeNode &obj)
    : value(obj.value), count(obj.count), left(obj.left), right(obj.right) ,refCnt(obj.refCnt){++*refCnt;}
  TreeNode &operator=(const TreeNode &rhs) {
    ++*rhs.refCnt;
    if (--*refCnt) {
      if (left) {
        delete left;
        left = nullptr;
      }
      if (right) {
        delete right;
        right = nullptr;
      }
      delete refCnt;
      refCnt = nullptr;
    }
    value = rhs.value;
    count = rhs.count;
    left = rhs.left;
    right = rhs.right;
    refCnt = rhs.refCnt;
    return *this;
  }
  ~TreeNode() {
    if (--*refCnt) {
      if (left) {
        left->right = nullptr;
      }
      if (right) {
        delete right;
        right = nullptr;
      }
      delete refCnt;
      refCnt = nullptr;
    }
  }

private:
  std::string value;
  int count;
  TreeNode *left;
  TreeNode *right;
  int *refCnt;
};

class BinStrTree {
public:
  BinStrTree() : root(new TreeNode()) { }
  BinStrTree(const BinStrTree &obj) : root(new TreeNode(*obj.root)){ }
  BinStrTree &operator=(const BinStrTree &rhs) {
    auto newp = new TreeNode(*rhs.root);
    delete root;
    root = newp;
    return *this;
  }
private:
  TreeNode *root;
};

#endif
