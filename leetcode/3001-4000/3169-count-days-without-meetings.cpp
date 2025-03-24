#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countDays(int days, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end());

    int prv = 0, cnt = 0;
    for (int i = 0; i < meetings.size(); i++) {
      int s = meetings[i][0], e = meetings[i][1];
      if (s > prv + 1) cnt += s - prv - 1;
      prv = max(prv, e);
    }

    cnt += days - prv;

    return cnt;
  }
};