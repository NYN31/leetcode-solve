#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size(), ans = 0, mx = 0;
    vector<int> left(n, 0), right(n, 0);

    for (int i = 1; i < n - 1; i++) {
      mx = max(mx, height[i - 1]);
      left[i] = mx;
    }

    mx = 0;
    for (int i = n - 2; i > 0; --i) {
      mx = max(mx, height[i + 1]);
      right[i] = mx;
    }

    for (int i = 1; i < n - 1; i++) {
      int mn = min(left[i], right[i]);
      int res = mn * 3 - (mn * 2 + height[i]);
      if(res > 0) ans += res;
    }

    return ans;
  }
};