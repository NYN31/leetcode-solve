#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long minimumSteps(string s) {
    int oneCount = 0;
    long long steps = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1')
        oneCount += 1;
      else
        steps += oneCount;
    }

    return steps;
  }
};