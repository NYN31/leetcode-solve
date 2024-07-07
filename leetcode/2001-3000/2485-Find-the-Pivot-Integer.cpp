#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int pivotInteger(int n) {
    if (n == 1) return 1;

    int ans = -1, total = (n * (n + 1)) / 2;
    for (int i = 1; i <= n; i++) {
      int l = (i * (i + 1)) / 2;
      int e = total - l + i;
      if (l == e) {
        ans = i;
        break;
      }
    }
    return ans;
  }
};