#include <bits/stdc++.h>
using namespace std;

// 1st approach
// time ans space complexity: O(n*n), O(1)
class Solution {
  int opt(int& j, int& k, vector<int>& nums) {
    long long mul = nums[j];
    if (mul >= k) return 0;
    int cnt = 1;
    for (int i = j + 1; i < nums.size(); i++) {
      mul *= nums[i];
      if (mul < k)
        cnt += 1;
      else
        break;
    }
    return cnt;
  }

 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      ans += opt(i, k, nums);
    }
    return ans;
  }
};

class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int left = 0, right = 0, mul = 1, cnt = 0;
    for (right = 0; right < nums.size(); right++) {
      mul *= nums[right];
      while (left < right && mul >= k) {
        mul /= nums[left++];
      }
      if (mul < k) cnt += right - left + 1;
    }
    return cnt;
  }
};