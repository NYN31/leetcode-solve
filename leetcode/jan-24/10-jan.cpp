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
#define sz 100005
class Solution {
 public:
  int node = 1;
  vector<vector<int>> adj = vector<vector<int>>(sz);

  void add(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    node = max({node, u, v});
  }

  void makeGraph(TreeNode* root) {
    if (root == NULL) return;
    if (root->left) add(root->val, root->left->val);
    makeGraph(root->left);
    if (root->right) add(root->val, root->right->val);
    makeGraph(root->right);
  }

  int bfs(int src, vector<bool>& visit, vector<int>& level) {
    queue<int> q;
    q.push(src);
    visit[src] = true;
    int max_dis = 0;
    while (!q.empty()) {
      int top = q.front();
      q.pop();

      for (auto node : adj[top]) {
        if (!visit[node]) {
          visit[node] = true;
          q.push(node);
          level[node] = level[top] + 1;
          max_dis = max(max_dis, level[node]);
        }
      }
    }
    return max_dis;
  }

  int amountOfTime(TreeNode* root, int start) {
    makeGraph(root);
    vector<bool> visit(node + 5, false);
    vector<int> level(node + 5, 0);
    return bfs(start, visit, level);
  }
};