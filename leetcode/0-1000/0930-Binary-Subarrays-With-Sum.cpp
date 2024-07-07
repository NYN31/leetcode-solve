#include <bits/stdc++.h>
using namespace std;

// Approach one
class Solution {
 public:
  int numSubarraysWithSum(vector<int>& nums, int goal) {
    int n = nums.size(), total = 0, currSum = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
      currSum += nums[i];
      if (mp.find(currSum - goal) != mp.end()) total += mp[currSum - goal];
      mp[currSum]++;
    }
    return total;
  }
};