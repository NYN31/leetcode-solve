#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findCenter(vector<vector<int>>& edges) {
    unordered_map<int, int> hash;
    int centerNode;

    for (int i = 0; i < edges.size(); i++) {
      int u = edges[i][0], v = edges[i][1];
      hash[u]++, hash[v]++;
      if (hash[u] > 1) return u;
      if (hash[v] > 1) return v;
    }

    return 0;
  }
};