#include <bits/stdc++.h>
using namespace std;

class Solution {
  void dfs(int src, vector<vector<int>>& graph, vector<bool>& visited) {
    if (visited[src]) return;
    visited[src] = true;
    for (auto node : graph[src]) {
      dfs(node, graph, visited);
    }
  }

  void bfs(int src, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
      int top = q.front();
      q.pop();

      for (auto node : graph[top]) {
        if (!visited[node]) {
          q.push(node);
          visited[node] = true;
        }
      }
    }
  }

 public:
  bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
    vector<bool> visited(n + 1, false);
    vector<vector<int>> graph(n);
    for (int i = 0; i < edges.size(); i++) {
      graph[edges[i][0]].push_back(edges[i][1]);
      graph[edges[i][1]].push_back(edges[i][0]);
    }
    bfs(src, graph, visited);
    return visited[dest];
  }
};