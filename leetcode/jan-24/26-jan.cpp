class Solution {
 public:
  int x[4] = {0, -1, 0, 1};
  int y[4] = {1, 0, -1, 0};
  int dp[52][52][52];
  int mod = 1e9 + 7;

  int fn(int i, int j, int rem, int& row, int& col) {
    if (i >= row || i < 0 || j >= col || j < 0) {
      return rem >= 0;
    }
    if (rem <= 0) return 0;
    if (dp[i][j][rem] != -1) return dp[i][j][rem];

    int ans = 0;
    for (int k = 0; k < 4; k++) {
      int dx = i + x[k], dy = j + y[k];
      ans = (ans + fn(dx, dy, rem - 1, row, col)) % mod;
    }

    dp[i][j][rem] = ans;
    return ans;
  }

  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    memset(dp, -1, sizeof(dp));
    return fn(startRow, startColumn, maxMove, m, n);
  }
};