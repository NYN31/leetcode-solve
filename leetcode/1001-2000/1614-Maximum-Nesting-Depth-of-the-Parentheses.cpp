#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxDepth(string s) {
    int currentDepth = 0, maxDepth = 0;
    for (auto& ch : s) {
      if (ch == '(') {
        currentDepth++;
        maxDepth = max(maxDepth, currentDepth);
      } else if (ch == ')')
        currentDepth--;
    }
    return maxDepth;
  }
};