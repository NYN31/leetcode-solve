#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> getFinalState(vector<int>& nums, int& k, int& multiplier) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    for (int i = 0; i < nums.size(); i++) {
      pq.push({nums[i], i});
    }

    for (int i = 0; i < k; i++) {
      pair<int, int> p = pq.top();
      pq.pop();
      int multipliedValue = p.first * multiplier;
      pq.push({multipliedValue, p.second});
      nums[p.second] = multipliedValue;
    }

    return nums;
  }
};