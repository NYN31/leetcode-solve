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
  void makeAdjacenyList(TreeNode *root,
                        unordered_map<int, vector<pair<int, char>>> &graph) {
    if (root->left) {
      graph[root->val].push_back({root->left->val, 'L'});
      graph[root->left->val].push_back({root->val, 'U'});
      makeAdjacenyList(root->left, graph);
    }
    if (root->right) {
      graph[root->val].push_back({root->right->val, 'R'});
      graph[root->right->val].push_back({root->val, 'U'});
      makeAdjacenyList(root->right, graph);
    }
  }

  bool dfs(int root, int destValue, string &direction, vector<bool> &vis,
           unordered_map<int, vector<pair<int, char>>> &graph) {
    if (root == destValue) {
      return true;
    }
    vis[root] = true;
    for (auto &adj : graph[root]) {
      if (!vis[adj.first]) {
        direction += adj.second;
        if (dfs(adj.first, destValue, direction, vis, graph)) {
          return true;
        }
        direction.pop_back();
      }
    }
    return false;
  }

 public:
  string getDirections(TreeNode *root, int startValue, int destValue) {
    unordered_map<int, vector<pair<int, char>>> graph;
    makeAdjacenyList(root, graph);
    vector<bool> vis(graph.size() + 1);
    string direction;
    dfs(startValue, destValue, direction, vis, graph);
    return direction;
  }
};