class Solution {
 public:
  vector<int> dp;

  int fn(int s, int& n) {
    if (s >= n) return s == n;
    int& ans = dp[s];
    if (ans != -1) return ans;

    ans = fn(s + 1, n) + fn(s + 2, n);
    return ans;
  }
  int climbStairs(int n) {
    dp.assign(n + 5, -1);
    return fn(0, n);
  }
};