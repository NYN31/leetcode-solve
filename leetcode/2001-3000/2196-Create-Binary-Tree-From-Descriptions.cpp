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
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    unordered_map<int, TreeNode *> nodesMp;
    unordered_set<int> children;

    for (auto &des : descriptions) {
      int parent = des[0], child = des[1], isLeft = des[2];

      if (nodesMp.count(parent) == 0) {
        nodesMp[parent] = new TreeNode(parent);
      }

      if (nodesMp.count(child) == 0) {
        nodesMp[child] = new TreeNode(child);
      }

      if (isLeft) {
        nodesMp[parent]->left = nodesMp[child];
      } else {
        nodesMp[parent]->right = nodesMp[child];
      }

      children.insert(child);
    }

    for (auto &entry : nodesMp) {
      auto &value = entry.first;
      auto &node = entry.second;
      if (children.find(value) == children.end()) {
        return node;
      }
    }

    return nullptr;
  }
};