#include <bits/stdc++.h>
using namespace std;

// Approach one
class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int mx = *max_element(nums.begin(), nums.end());
    vector<int> count(mx + 1, 0), output(mx + 1, 0);
    for (auto& num : nums) count[num] += 1;
    for (int i = 1; i <= mx; i++) {
      count[i] += count[i - 1];
    }
    for (int i = 0; i < n; i++) {
      output[count[nums[i]] - 1] = nums[i];
      count[nums[i]]--;
    }

    for (int i = 0; i < n; i++) {
      if (i != output[i]) {
        n = i;
        break;
      }
    }
    return n;
  }
};

// 2nd Approach
class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int sum = 0, n = nums.size();
    for (auto& num : nums) sum += num;
    return (n * (n + 1)) / 2 - sum;
  }
};