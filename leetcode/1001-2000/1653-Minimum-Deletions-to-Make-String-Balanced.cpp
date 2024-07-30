#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minimumDeletions(string s) {
    int n = s.size(), cnta = 0, cntb = 0;

    for (int i = 0; i < n; i++) {
      if (s[i] == 'a') cnta++;
    }

    int mnDel = n;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a') cnta--;
      mnDel = min(mnDel, cnta + cntb);
      if (s[i] == 'b') cntb++;
    }

    return mnDel;
  }
};