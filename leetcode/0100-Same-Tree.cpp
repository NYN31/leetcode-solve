#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
  bool fn(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr)
      return true;
    else if (p == nullptr || q == nullptr)
      return false;
    else if (p->val != q->val)
      return false;
    else
      return fn(p->left, q->left) && fn(p->right, q->right);
  }

 public:
  bool isSameTree(TreeNode* p, TreeNode* q) { return fn(p, q); }
};