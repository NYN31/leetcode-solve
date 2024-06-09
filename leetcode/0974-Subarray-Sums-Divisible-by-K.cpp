#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> hash;
    int cnt = 0, rem = 0;

    hash[0] = 1;
    for (int i = 0; i < nums.size(); i++) {
      rem = ((rem + nums[i]) % k + k) % k;
      cnt += hash[rem];
      hash[rem] += 1;
    }

    return cnt;
  }
};