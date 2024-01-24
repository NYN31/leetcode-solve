/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  int occur[10];
  int fn(TreeNode* root) {
    if (root == nullptr) return 0;
    occur[root->val] += 1;

    int ans = fn(root->left);
    ans += fn(root->right);

    if (root->left == nullptr && root->right == nullptr) {
      int odd = 0, even = 0;
      for (int i = 1; i <= 9; i++) {
        if (occur[i] & 1)
          odd++;
        else
          even++;
      }

      if (odd <= 1) {
        occur[root->val] -= 1;
        return 1;
      }
    }
    occur[root->val] -= 1;
    return ans;
  }
  int pseudoPalindromicPaths(TreeNode* root) { return fn(root); }
};