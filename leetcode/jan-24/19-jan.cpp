class Solution {
 public:
  int dp[101][101];

  int fn(int row, int col, vector<vector<int>>& mat) {
    if (col >= mat.size() || col < 0) return INT_MAX;
    if (row == mat.size() - 1) return mat[row][col];
    int& ans = dp[row][col];
    if (ans != INT_MAX) return ans;

    int ans1 = fn(row + 1, col - 1, mat);
    int ans2 = fn(row + 1, col, mat);
    int ans3 = fn(row + 1, col + 1, mat);

    ans = min(min(ans1, ans2), ans3) + mat[row][col];
    return ans;
  }

  int minFallingPathSum(vector<vector<int>>& matrix) {
    int ans = INT_MAX;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix.size(); j++) {
        dp[i][j] = INT_MAX;
      }
    }
    for (int col = 0; col < matrix.size(); col++) {
      ans = min(ans, fn(0, col, matrix));
    }
    return ans;
  }
};