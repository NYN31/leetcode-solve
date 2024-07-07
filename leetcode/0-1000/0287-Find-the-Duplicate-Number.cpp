#include <bits/stdc++.h>
using namespace std;

// First Approach
class Solution {
 public:
  int findDuplicate(vector<int> &nums) {
    int slow = nums[0], fast = nums[0];
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }
    fast = nums[0];
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
  }
};

// Second approach
class Solution {
 public:
  int findDuplicate(vector<int> &nums) {
    int ans, size = nums.size();
    for (auto e : nums) {
      nums[e % (size)] += size;
    }

    for (int i = 0; i < size; i++) {
      if ((nums[i] / size) > 1) {
        ans = i;
        break;
      }
    }
    return ans;
  }
};