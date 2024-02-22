/*
 * Title: Leetcode Problem
 * Description: Leetcode 75
 * Author: Md Sajjad Hosen Noyon
 * Handle: NOYON31
 * Date: 22/02/2024
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for (int i = 0; i < nums.size(); i++) pq.push(nums[i]);
    int ans;
    while (true) {
      ans = pq.top();
      pq.pop();
      k--;
      if (k == 0) break;
    }
    return ans;
  }
};
