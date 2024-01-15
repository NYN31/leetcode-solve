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
  void traverse(TreeNode* root, vector<int>& leaf) {
    if (root == NULL) return;
    traverse(root->left, leaf);
    traverse(root->right, leaf);
    if (root->left == NULL && root->right == NULL) leaf.push_back(root->val);
    return;
  }
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leaf1, leaf2;
    traverse(root1, leaf1);
    traverse(root2, leaf2);

    if (leaf1.size() != leaf2.size()) return false;

    for (int i = 0; i < leaf1.size(); i++) {
      if (leaf1[i] != leaf2[i]) {
        return false;
      }
    }
    return true;
  }
};