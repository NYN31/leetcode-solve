#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int temp[50005];

  void merge_sort(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;

    merge_sort(nums, l, mid);
    merge_sort(nums, mid + 1, r);

    int i, j, k;
    for (i = l, j = mid + 1, k = l; k <= r; k++) {
      if (i == mid + 1) temp[k] = nums[j++];
      if (j == r + 1) temp[k] = nums[i++];
      if (nums[i] < nums[j])
        temp[k] = nums[i++];
      else
        temp[k] = nums[j++];
    }

    for (int i = l; i <= r; i++) nums[i] = temp[i];
  }

  vector<int> sortArray(vector<int>& nums) {
    merge_sort(nums, 0, nums.size() - 1);
    return nums;
  }
};