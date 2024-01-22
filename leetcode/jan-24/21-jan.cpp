class Solution {
 public:
  int fn(int i, int& n, vector<int>& dp, vector<int>& nums) {
    if (i >= n) return 0;
    int& ans = dp[i];
    if (ans != -1) return ans;

    ans = fn(i + 1, n, dp, nums);
    ans = max(ans, fn(i + 2, n, dp, nums) + nums[i]);

    return ans;
  }
  int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n + 5, -1);
    return fn(0, n, dp, nums);
  }
};
