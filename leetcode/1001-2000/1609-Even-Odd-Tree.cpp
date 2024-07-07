#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// Solution 01: using DFS
class Solution {
 public:
  int findDepth(TreeNode* root, int depth) {
    if (!root) return 0;
    int l = findDepth(root->left, depth + 1);
    int r = findDepth(root->right, depth + 1);
    return max(l, r) + 1;
  }
  void traverse(TreeNode* root, int depth, vector<vector<int>>& nodes) {
    if (!root) return;
    nodes[depth].push_back(root->val);
    traverse(root->left, depth + 1, nodes);
    traverse(root->right, depth + 1, nodes);
  }
  bool checkOddIncOrder(vector<int>& arr) {
    if (arr[0] % 2 == 0) return false;
    for (int i = 1; i < arr.size(); i++) {
      if (arr[i] % 2 == 0 || arr[i] <= arr[i - 1]) {
        return false;
      }
    }
    return true;
  }
  bool checkEvenDecOrder(vector<int>& arr) {
    if (arr[0] % 2 == 1) return false;
    for (int i = 1; i < arr.size(); i++) {
      if (arr[i] % 2 == 1 || arr[i] >= arr[i - 1]) {
        return false;
      }
    }
    return true;
  }
  bool isEvenOddTree(TreeNode* root) {
    int depth = findDepth(root, 0);
    vector<vector<int>> nodes(depth);
    traverse(root, 0, nodes);
    bool isEvenOdd = true;
    for (int i = 0; i < nodes.size() && isEvenOdd; i++) {
      if (i % 2 == 0)
        isEvenOdd = checkOddIncOrder(nodes[i]);
      else
        isEvenOdd = checkEvenDecOrder(nodes[i]);
    }
    return isEvenOdd;
  }
};

// Solution 02: using BFS
class Solution {
 public:
  bool isEvenOddTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
      int n = q.size();
      if (level & 1) {
        int prev = INT_MAX;
        for (int i = 0; i < n; i++) {
          if (q.front()->val >= prev) return false;

          prev = q.front()->val;
          if (q.front()->val % 2 == 1) return false;
          if (q.front()->left) q.push(q.front()->left);
          if (q.front()->right) q.push(q.front()->right);
          q.pop();
        }
      } else {
        int prev = INT_MIN;
        for (int i = 0; i < n; i++) {
          if (q.front()->val <= prev) return false;

          prev = q.front()->val;
          if (q.front()->val % 2 == 0) return false;
          if (q.front()->left) q.push(q.front()->left);
          if (q.front()->right) q.push(q.front()->right);
          q.pop();
        }
      }
      level++;
    }
    return true;
  }
};