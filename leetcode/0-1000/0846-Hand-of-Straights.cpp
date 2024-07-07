#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isNStraightHand(vector<int>& hand, int groupSize) {
    int n = hand.size();
    if (n % groupSize != 0) return false;
    sort(hand.begin(), hand.end());
    vector<vector<int>> v;
    vector<bool> used(n, false);
    while (v.size() < (n / groupSize)) {
      vector<int> cur;
      int start = -1;
      for (int i = 0; i < n; i++) {
        if (used[i] == false) {
          start = i;
          break;
        }
      }
      while (start < n && cur.size() < groupSize) {
        if (used[start] == false) {
          if (cur.size() == 0 || cur[cur.size() - 1] != hand[start]) {
            cur.push_back(hand[start]);
            used[start] = true;
          }
        }
        start++;
      }
      v.push_back(cur);
    }
    for (auto cur : v) {
      if (cur.size() != groupSize) return false;
      for (int i = 1; i < cur.size(); i++) {
        if (cur[i - 1] + 1 != cur[i]) {
          return false;
        }
      }
    }
    return true;
  }
};