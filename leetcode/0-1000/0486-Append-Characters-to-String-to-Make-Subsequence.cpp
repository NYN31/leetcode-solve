#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int appendCharacters(string s, string t) {
    int sidx = 0, tidx = 0;
    while (sidx < s.size()) {
      if (s[sidx] == t[tidx]) {
        sidx += 1;
        tidx += 1;
      } else
        sidx += 1;
    }

    return t.size() - tidx + 1;
  }
};