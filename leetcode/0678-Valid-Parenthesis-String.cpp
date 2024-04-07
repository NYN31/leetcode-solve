#include <bits/stdc++.h>
using namespace std;

class Solution {
  int dp[101][101];
  bool fn(int idx, int open, string& s) {
    if (idx == s.size()) return open == 0;
    int& ans = dp[idx][open];
    if (ans != -1) return ans;
    bool isValid = false;
    if (s[idx] == '*') {
      isValid |= fn(idx + 1, open + 1, s);
      isValid |= fn(idx + 1, open, s);
      if (open > 0) isValid |= fn(idx + 1, open - 1, s);
    } else {
      if (s[idx] == '(')
        isValid |= fn(idx + 1, open + 1, s);
      else if (open > 0)
        isValid |= fn(idx + 1, open - 1, s);
    }
    return ans = isValid;
  }

 public:
  bool checkValidString(string s) {
    memset(dp, -1, sizeof dp);
    return fn(0, 0, s);
  }
};