#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    int x_or = nums[0], cnt = 0;
    for (int i = 1; i < nums.size(); i++) {
      x_or ^= nums[i];
    }

    x_or = x_or ^ k;
    while (x_or) {
      if (x_or & 1) {
        cnt += 1;
      }
      x_or >>= 1;
    }

    return cnt;
  }
};