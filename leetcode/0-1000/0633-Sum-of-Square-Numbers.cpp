#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int fn(int c) {
    int lo = 0, hi = sqrt(c);
    while (lo <= hi) {
      long long ans = lo * lo + hi * hi * 1LL;
      if (ans == c) {
        return true;
      } else if (ans < c) {
        lo++;
      } else {
        hi--;
      }
    }

    return false;
  }

  bool judgeSquareSum(int c) { return fn(c); }
};