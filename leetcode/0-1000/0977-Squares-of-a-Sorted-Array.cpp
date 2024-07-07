#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int getSize(vector<int>& nums) {
    int mn = *min_element(nums.begin(), nums.end());
    int mx = *max_element(nums.begin(), nums.end());
    return max(mn * -1, mx);
  }
  vector<int> sortedSquares(vector<int>& nums) {
    int sz = getSize(nums) + 2;
    vector<int> freqCnt(sz, 0), ans;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < 0) nums[i] *= -1;
      freqCnt[nums[i]]++;
    }
    for (int i = 0; i < sz; i++) {
      if (freqCnt[i] == 0) continue;
      for (int j = 0; j < freqCnt[i]; j++) {
        ans.push_back(i * i);
      }
    }
    return ans;
  }
};