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
  int val = -1, max_depth = INT_MIN;
  void fn(TreeNode *root, int curr_depth) {
    if (root == nullptr) return;
    if (max_depth < curr_depth) {
      max_depth = curr_depth;
      val = root->val;
    }
    fn(root->left, curr_depth + 1);
    fn(root->right, curr_depth + 1);
  }
  int findBottomLeftValue(TreeNode *root) {
    fn(root, 0);
    return val;
  }
};