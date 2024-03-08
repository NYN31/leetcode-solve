#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxFrequencyElements(vector<int>& nums) {
    vector<int> frq(101, 0);
    int mx = -1;
    for (int i = 0; i < nums.size(); i++) {
      frq[nums[i]]++;
      mx = max(mx, frq[nums[i]]);
    }
    int ans = 0;
    for (int i = 1; i <= 100; i++) {
      if (frq[i] == mx) {
        ans++;
      }
    }
    return ans * mx;
  }
};