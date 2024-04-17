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
  string minReverse(string &str1, string &str2) {
    if (str1.empty()) {
      return str2;
    }
    int i = str1.size() - 1, j = str2.size() - 1;
    while (i >= 0 && j >= 0) {
      if (str1[i] < str2[j]) {
        return str1;
      }
      if (str1[i] > str2[j]) {
        return str2;
      }
      i--;
      j--;
    }
    if (str1.size() < str2.size()) {
      return str1;
    }
    if (str1.size() > str2.size()) {
      return str2;
    }
    return str1;
  }

  void dfs(TreeNode *root, string &currentStr, string &smallestFromRoot) {
    bool isChild = true;
    if (root->left) {
      isChild = false;
      currentStr += root->left->val + 'a';
      dfs(root->left, currentStr, smallestFromRoot);
      currentStr.pop_back();
    }

    if (root->right) {
      isChild = false;
      currentStr += root->right->val + 'a';
      dfs(root->right, currentStr, smallestFromRoot);
      currentStr.pop_back();
    }
    if (isChild) {
      smallestFromRoot = minReverse(smallestFromRoot, currentStr);
    }
  }

 public:
  string smallestFromLeaf(TreeNode *root) {
    string smallestFromRoot, currentStr;
    currentStr += root->val + 'a';
    dfs(root, currentStr, smallestFromRoot);
    reverse(smallestFromRoot.begin(), smallestFromRoot.end());
    return smallestFromRoot;
  }
};