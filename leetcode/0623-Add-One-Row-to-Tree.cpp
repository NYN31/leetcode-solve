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
  void dfs(TreeNode *root, int currentDepth, int val, int depth) {
    if (!root) {
      return;
    }
    if (currentDepth == depth - 1) {
      // TreeNode *originalLeft = root->left;
      //   TreeNode *originalRight = root->right;
      root->left = new TreeNode(val, root->left, nullptr);
      root->right = new TreeNode(val, nullptr, root->right);
      return;
    }
    currentDepth++;
    dfs(root->left, currentDepth, val, depth);
    dfs(root->right, currentDepth, val, depth);
  }

 public:
  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    if (depth == 1) {
      root = new TreeNode(val, root, nullptr);
    } else {
      dfs(root, 1, val, depth);
    }
    return root;
  }
};