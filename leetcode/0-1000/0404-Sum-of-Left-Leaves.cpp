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
  int sumOfLeftLeaves(TreeNode *root, bool isLeft = false) {
    if (!root) return 0;
    if (isLeft && !root->left && !root->right) return root->val;
    int sum1 = sumOfLeftLeaves(root->left, true);
    int sum2 = sumOfLeftLeaves(root->right, false);
    return sum1 + sum2;
  }
};