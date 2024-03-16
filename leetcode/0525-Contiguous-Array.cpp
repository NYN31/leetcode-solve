#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    for (auto& v : nums) {
      if (v == 0) v = -1;
    }

    unordered_map<int, int> mp;
    mp[0] = -1;
    int currsum = 0;
    int maxcount = 0;
    for (int i = 0; i < n; i++) {
      currsum += nums[i];

      if (mp.find(currsum - 0) != mp.end()) {
        maxcount = max(maxcount, i - mp[currsum - 0]);
      }

      if (mp.find(currsum) == mp.end()) mp[currsum] = i;
    }
    return maxcount;
  }
};