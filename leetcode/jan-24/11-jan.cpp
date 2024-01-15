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
  int dis = -1e9;
  void fn(TreeNode* root, int& mx, int& mn) {
    if (root == nullptr) return;
    int mxa = max(mx, root->val);
    int mnb = min(mn, root->val);
    fn(root->left, mxa, mnb);
    fn(root->right, mxa, mnb);
    dis = max(dis, abs(mxa - mnb));
    return;
  }

  int maxAncestorDiff(TreeNode* root) {
    fn(root, root->val, root->val);
    return dis;
  }
};