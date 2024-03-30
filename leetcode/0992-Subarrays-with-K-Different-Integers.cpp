#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // find subarrays with at most k different integer
  int good_subarray(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    int start = 0, end = 0, ans = 0;
    for (end = 0; end < nums.size(); end++) {
      mp[nums[end]]++;
      while (mp.size() > k) {
        mp[nums[start]]--;
        if (mp[nums[start]] == 0) mp.erase(nums[start]);
        start++;
      }
      ans += end - start + 1;
    }
    return ans;
  }
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    return good_subarray(nums, k) - good_subarray(nums, k - 1);
  }
};