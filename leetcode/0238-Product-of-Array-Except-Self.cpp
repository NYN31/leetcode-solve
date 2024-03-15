#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int count0 = 0, total_mul = 1;
    vector<int> ans(nums.size(), 0);
    for (auto& val : nums) {
      if (val == 0)
        count0++;
      else
        total_mul *= val;
    }

    if (count0 >= 2) {
      return ans;
    } else if (count0 == 1) {
      int idx = -1;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
          idx = i;
          break;
        }
      }
      ans[idx] = total_mul;
      return ans;
    } else {
      for (int i = 0; i < nums.size(); i++) {
        ans[i] = total_mul / nums[i];
      }
      return ans;
    }
  }
};