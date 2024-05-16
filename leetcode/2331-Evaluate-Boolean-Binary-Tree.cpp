#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool fn(TreeNode *root) {
    if (root->val == 0)
      return false;
    else if (root->val == 1)
      return true;

    bool l = fn(root->left);
    bool r = fn(root->right);

    bool ans;
    if (root->val == 2)
      ans = l || r;
    else if (root->val == 3)
      ans = l & r;

    return ans;
  }
  bool evaluateTree(TreeNode *root) { return fn(root); }
};