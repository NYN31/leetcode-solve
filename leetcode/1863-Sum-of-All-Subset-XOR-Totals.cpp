#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int fn(int i, vector<int>& nums, int xr = 0) {
    if (i == nums.size()) return xr;
    int notTake = fn(i + 1, nums, xr);
    int take = fn(i + 1, nums, xr ^ nums[i]);
    return take + notTake;
  }

  int subsetXORSum(vector<int>& nums) { return fn(0, nums); }
};