#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minDifference(vector<int>& nums) {
    int len = nums.size() - 1, idx = 0;
    if (len <= 4) return 0;

    sort(nums.begin(), nums.end());
    return min({nums[len] - nums[idx + 3], nums[len - 1] - nums[idx + 2],
                nums[len - 2] - nums[idx + 1], nums[len - 3] - nums[idx]});
  }
};

class Solution {
 public:
  int minDifference(vector<int>& nums) {
    int len = nums.size();
    if (nums.size() <= 4) return 0;

    sort(nums.begin(), nums.end());
    return min({abs(nums[0] - nums[len - 4]), abs(nums[1] - nums[len - 3]),
                abs(nums[2] - nums[len - 2]), abs(nums[3] - nums[len - 1])});
  }
};
