#include <bits/stdc++.h>
using namespace std;

// approach 1
// Time complexity: O(n * log(n)), Space complexity: O(1)
class Solution {
  long long getMin(vector<int>& nums) {
    int ans = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] <= 0) continue;
      if (nums[i] < ans) ans = nums[i];
    }
    return ans * 1LL;
  }

 public:
  int firstMissingPositive(vector<int>& nums) {
    long long mn = getMin(nums);
    int n = nums.size();
    if (mn > 1) return 1;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] <= 0) nums[i] = mn;
    }
    sort(nums.begin(), nums.end());
    mn = nums[n - 1] + 1LL;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i + 1] - nums[i] > 1) {
        mn = nums[i] + 1;
        break;
      }
    }
    return int(mn);
  }
};

// approach 2
// Time complexity: O(n), Space complexity: O(1)
class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    for (auto& num : nums) {
      if (num < 0) num = 0;
    }

    for (int i = 0; i < nums.size(); i++) {
      int idx = abs(nums[i]) - 1;
      if (nums[i] != 0 && idx < nums.size()) {
        if (nums[idx] == 0)
          nums[idx] = -(nums.size() + 1);
        else if (nums[idx] > 0)
          nums[idx] *= -1;
      }
    }

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] >= 0) return i + 1;
    }

    return nums.size() + 1;
  }
};
