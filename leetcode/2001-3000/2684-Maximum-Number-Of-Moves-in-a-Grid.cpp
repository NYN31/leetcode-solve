#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int steps(int r, int c, int prev, int& m, int& n, vector<vector<int>>& grid,
            vector<vector<int>>& dp) {
    if (r < 0 || c < 0 || r >= m || c >= n) return 0;
    if (prev >= grid[r][c]) return 0;

    int& ret = dp[r][c];
    if (ret != -1) return ret;

    ret = max({steps(r - 1, c + 1, grid[r][c], m, n, grid, dp),
               steps(r, c + 1, grid[r][c], m, n, grid, dp),
               steps(r + 1, c + 1, grid[r][c], m, n, grid, dp)}) +
          1;

    return ret;
  }

  int maxMoves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    int mxSteps = 0;
    for (int i = 0; i < m; i++) {
      mxSteps = max(mxSteps, steps(i, 0, 0, m, n, grid, dp));
    }

    return mxSteps - 1;
  }
};