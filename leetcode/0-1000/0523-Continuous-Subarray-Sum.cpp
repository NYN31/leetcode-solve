#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> hash;
    int sum = 0;
    hash[0] = -1;

    for (int i = 0; i < n; i++) {
      sum += nums[i];
      int rem = sum % k;

      if (hash.find(rem) != hash.end()) {
        if (i - hash[rem] >= 2) {
          return true;
        }
      } else {
        hash[rem] = i;
      }
    }
    return false;
  }
};