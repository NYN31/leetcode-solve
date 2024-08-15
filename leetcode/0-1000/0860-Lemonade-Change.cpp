#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool lemonadeChange(vector<int>& bills) {
    int cnt5 = 0, cnt10 = 0, cnt20 = 0;

    for (auto& bill : bills) {
      if (bill == 20) {
        cnt20++;
        if (cnt5 >= 1 && cnt10 >= 1) {
          cnt5--, cnt10--;
        } else if (cnt5 >= 3) {
          cnt5 -= 3;
        } else return false;

      } else if (bill == 10) {
            cnt10++;
            if (cnt5 >= 1) cnt5--;
            else return false;
      } else cnt5++;
    }

    return true;
  }
};