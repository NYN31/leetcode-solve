#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void mySort(vector<int>& nums, int val, int cnt, int idx) {
    for (int i = idx; i < nums.size() && cnt != 0; i += 1) {
      nums[i] = val;
      cnt -= 1;
    }
  }

  void sortColors(vector<int>& nums) {
    int hash[3] = {0};
    for (auto& num : nums) {
      hash[num]++;
    }

    int idx = 0;
    mySort(nums, 0, hash[0], idx);
    mySort(nums, 1, hash[1], hash[0]);
    mySort(nums, 2, hash[2], hash[0] + hash[1]);
  }
};