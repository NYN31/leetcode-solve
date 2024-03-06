#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minimumLength(string s) {
    int lo = 0, hi = s.size() - 1;
    char curr;

    if (s[lo] == s[hi] && hi > 0)
      curr = s[lo];
    else
      return hi + 1;
    while (lo < hi) {
      if (s[lo] == s[hi]) {
        curr = s[lo];
      } else if (s[lo] != curr && s[hi] != curr)
        break;

      if (s[lo] == curr) lo++;
      if (s[hi] == curr) hi--;
    }
    if (lo == hi && curr == s[lo]) lo++;

    return hi - lo + 1;
  }
};