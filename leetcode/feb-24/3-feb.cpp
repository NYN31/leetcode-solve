class Solution {
 public:
  int fn(int idx, int k, vector<int>& arr, vector<int>& dp) {
    int maxValue = -1, n = arr.size();
    if (idx >= n) return 0;
    int& ans = dp[idx];
    if (ans != -1) return ans;

    for (int i = idx; i < min(n, idx + k); i++) {
      maxValue = max(maxValue, arr[i]);
      ans = max(ans, (i - idx + 1) * maxValue + fn(i + 1, k, arr, dp));
    }
    return ans;
  }
  int maxSumAfterPartitioning(vector<int>& arr, int k) {
    vector<int> dp(arr.size() + 1, -1);
    return fn(0, k, arr, dp);
  }
};