class Solution {
 public:
  int dp[1005][1005];
  int fn(int i, int j, string& t1, string& t2) {
    if (i >= t1.size() || j >= t2.size()) return 0;
    int& ans = dp[i][j];
    if (ans != -1) return ans;

    if (t1[i] == t2[j])
      ans = fn(i + 1, j + 1, t1, t2) + 1;
    else
      ans = max(fn(i + 1, j, t1, t2), fn(i, j + 1, t1, t2));
    return ans;
  }
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) dp[i][j] = -1;
    return fn(0, 0, text1, text2);
  }
};