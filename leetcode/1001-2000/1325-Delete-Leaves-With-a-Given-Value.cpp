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
  void dfs(TreeNode *root, int &target) {
    if (!root) return;

    dfs(root->left, target);
    dfs(root->right, target);

    if (!root->left && !root->right && root->val == target) {
      root = nullptr;
    }
  }

  TreeNode *removeLeafNodes(TreeNode *root, int target) {
    dfs(root, target);
    return root;
  }
};