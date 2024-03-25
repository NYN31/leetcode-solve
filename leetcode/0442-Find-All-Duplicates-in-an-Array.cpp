#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size();

    vector<int> ans;
    for (auto& e : nums) {
      int idx = e % n;
      if (idx == 0) idx = n - 1;
      else idx--;
      nums[idx] += n;
    }

    for (int i = 0; i < n; i++) {
      if (nums[i] / n < 2 || (nums[i] / n == 2 && nums[i] % n == 0))
        continue;
      else ans.push_back(i + 1);
    }
    
    return ans;
  }
};