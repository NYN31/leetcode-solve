#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countSeniors(vector<string>& details) {
    int cnt = 0;
    for (string& detail : details) {
      char f = detail[11], s = detail[12];
      if (f <= '6' && s == '0') continue;
      if (f >= '6') cnt++;
    }

    return cnt;
  }
};