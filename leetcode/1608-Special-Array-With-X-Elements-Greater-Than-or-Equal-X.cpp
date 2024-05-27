#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int helper(vector<int>& nums, int x) {
    int l = 0;
    int h = nums.size() - 1;
    int idx = nums.size();
    while (l <= h) {
      int m = (l + h) / 2;
      if (nums[m] >= x) {
        idx = m;
        h = m - 1;
      } else {
        l = m + 1;
      }
    }
    return idx;
  }
  int specialArray(vector<int>& nums) {
    int n = nums.size();
    int x = 1;
    sort(nums.begin(), nums.end());
    while (x <= n) {
      int idx = helper(nums, x);
      if (n - idx == x) return x;
      x++;
    }
    return -1;
  }
};