#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minIncrementForUnique(vector<int>& nums) {
    map<int, int> existNo;
    deque<int> dq;
    int ans = 0;

    for (int num : nums) existNo[num]++;
    for (int i = 0; i < 200100; i++) {
      if (existNo.find(i) == existNo.end()) {
        dq.push_back(i);
      }
    }

    for (auto& [key, value] : existNo) {
      if (value > 1) {
        while (!dq.empty()) {
          int frontValue = dq.front();
          dq.pop_front();
          if (key < frontValue) {
            ans += frontValue - key;
            value--;
          }
          if (value <= 1) break;
        }
      }
    }

    return ans;
  }
};