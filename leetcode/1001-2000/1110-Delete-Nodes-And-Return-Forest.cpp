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
  vector<TreeNode *> ans;

  void fn(TreeNode *root, TreeNode *par, bool isLeft, int currVal) {
    if (!root) return;

    if (root->val == currVal) {
      if (root->left) ans.push_back(root->left);
      if (root->right) ans.push_back(root->right);
      if (!par) return;
      if (isLeft)
        par->left = nullptr;
      else
        par->right = nullptr;

      return;
    }

    fn(root->left, root, 1, currVal);
    fn(root->right, root, 0, currVal);
  }

  void newDeleteArray(TreeNode *root, vector<int> &to_delete,
                      vector<int> &new_delete, int hash[]) {
    if (!root) return;
    if (hash[root->val]) new_delete.push_back(root->val);
    newDeleteArray(root->left, to_delete, new_delete, hash);
    newDeleteArray(root->right, to_delete, new_delete, hash);
  }

  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    int hash[1005] = {0};
    for (int i = 0; i < to_delete.size(); i++) hash[to_delete[i]] = 1;

    vector<int> new_delete;
    newDeleteArray(root, to_delete, new_delete, hash);
    reverse(new_delete.begin(), new_delete.end());

    if (root->val != new_delete[new_delete.size() - 1]) {
      ans.push_back(root);
    }

    for (int i = 0; i < new_delete.size(); i++) {
      fn(root, nullptr, 0, new_delete[i]);
    }

    return ans;
  }
};