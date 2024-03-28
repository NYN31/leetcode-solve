#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxSubarrayLength(vector<int>& nums, int k) {
    if (k == 0) return 0;
    unordered_map<int, int> fq;
    int left = 0, right = 0, ans = 0;
    for (right = 0; right < nums.size(); right++) {
      fq[nums[right]]++;
      while (fq[nums[right]] > k && left < right) {
        fq[nums[left++]]--;
      }
      ans = max(ans, right - left + 1);
    }
    return ans;
  }
};