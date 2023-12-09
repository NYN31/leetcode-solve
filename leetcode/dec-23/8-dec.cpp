/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string str = "";
    bool f = true;
    void makeString(TreeNode* root) {
      if (root == NULL) return;
      
      str += to_string(root->val);
      if (root->left || root->right) {
        str += '(';
        makeString(root->left);
        str += ')';
       }
       if (root->right) {
        str += '(';
        makeString(root->right);
        str += ')';
      }
    }

    string tree2str(TreeNode* root) {
        makeString(root);
        return str;
    }
};