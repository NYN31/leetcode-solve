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
  int dfs(TreeNode *root, int curr = 0) {
    if (!root) return 0;
    if (root->left == nullptr && root->right == nullptr) {
      return curr * 10 + root->val;
    }
    curr = curr * 10 + root->val;
    int sum = 0;
    sum += dfs(root->left, curr);
    sum += dfs(root->right, curr);
    return sum;
  }
  int sumNumbers(TreeNode *root) { return dfs(root); }
};