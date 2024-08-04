#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  const int mod = 1e9 + 7;
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    vector<long long> subarr;

    for (int i = 0; i < n; i++) {
      long long sum = 0;
      for (int j = i; j < n; j++) {
        sum = (sum + nums[j]) % mod;
        subarr.push_back(sum);
      }
    }

    sort(subarr.begin(), subarr.end());
    int ans = 0;
    for (int i = left - 1; i < right; i++) {
      ans = (ans + subarr[i]) % mod;
    }

    return ans;
  }
};