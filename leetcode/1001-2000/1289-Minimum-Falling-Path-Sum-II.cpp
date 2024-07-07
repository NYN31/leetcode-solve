#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int dp[201][201];

  int findMin(int row, int col, vector<vector<int>>& grid) {
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid.size()) {
      return 0;
    }
    int& ans = dp[row][col];
    if (ans != -1) return ans;

    int mn = 1e9;
    for (int nxtRowCol = 0; nxtRowCol < grid.size(); nxtRowCol++) {
      if (nxtRowCol == col) continue;
      mn = min(mn, findMin(row + 1, nxtRowCol, grid) + grid[row][col]);
    }
    ans = mn;
    return ans;
  }

  int minFallingPathSum(vector<vector<int>>& grid) {
    if (grid.size() == 1) return grid[0][0];

    memset(dp, -1, sizeof dp);
    int mn = 1e9;
    for (int col = 0; col < grid.size(); col++) {
      mn = min(mn, findMin(0, col, grid));
    }
    return mn;
  }
};