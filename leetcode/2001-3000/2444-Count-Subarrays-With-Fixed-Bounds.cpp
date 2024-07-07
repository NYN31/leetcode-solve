#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    int left = 0, right = 0, mn = INT_MAX, mx = INT_MIN, n = nums.size();
    int mxPos = -1, mnPos = -1;
    long long ans = 0;
    while (right < n) {
      mx = max(mx, nums[right]);
      if (nums[right] == maxK) mxPos = right;
      mn = min(mn, nums[right]);
      if (nums[right] == minK) mnPos = right;
      if (mn < minK || mx > maxK) {
        mn = INT_MAX;
        mx = INT_MIN;
        left = right + 1;
        mnPos = right;
        mxPos = right;
      }
      right++;
      ans += min(mxPos, mnPos) - left + 1;
    }
    return ans;
  }
};