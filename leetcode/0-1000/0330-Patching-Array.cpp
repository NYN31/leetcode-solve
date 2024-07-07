#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minPatches(vector<int>& nums, int n) {
    int curr = 1, total = 0, cnt = 0, i = 0;

    while (total < n) {
      if (i >= nums.size() || nums[i] > curr) {
        cnt += 1;
        if(n - curr < total) return cnt;
        total += curr;
        curr <<= 1;
      } else {
        total += nums[i];
        curr = total + 1;
        ++i;
      }
    }

    return cnt;
  }
};