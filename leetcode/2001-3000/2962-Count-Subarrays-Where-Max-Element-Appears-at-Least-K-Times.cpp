#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int k) {
    int mxElm = *max_element(nums.begin(), nums.end());
    vector<int> mxElmIdx;
    long long ans = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == mxElm) mxElmIdx.push_back(i);
      int frq = mxElmIdx.size();
      if (frq >= k) {
        ans += mxElmIdx[frq - k] + 1;
      }
    }
    return ans;
  }
};