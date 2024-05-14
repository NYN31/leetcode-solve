#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int fn(int r, int c, int g, vector<vector<int>>& grid,
         vector<vector<int>>& vis, int& m, int& n) {
    if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0 || vis[r][c]) {
      return g;
    }

    vis[r][c] = true;
    int ans = fn(r, c + 1, g + grid[r][c], grid, vis, m, n);
    ans = max(ans, fn(r, c - 1, g + grid[r][c], grid, vis, m, n));
    ans = max(ans, fn(r + 1, c, g + grid[r][c], grid, vis, m, n));
    ans = max(ans, fn(r - 1, c, g + grid[r][c], grid, vis, m, n));
    vis[r][c] = false;

    return ans;
  }

  int getMaximumGold(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int ans = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        vector<vector<int>> vis(m, vector<int>(n, false));
        ans = max(ans, fn(i, j, 0, grid, vis, m, n));
      }
    }

    return ans;
  }
};