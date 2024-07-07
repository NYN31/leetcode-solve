#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numSteps(string s) {
    int carry = 0, steps = 0;
    deque<int> dq;
    for (int i = 0; i < s.size(); i++) {
      dq.push_back((int)(s[i] - '0'));
    }

    while (true) {
      int back = dq.back();
      dq.pop_back();

      if (dq.size() == 0) {
        break;
      }
      steps += 1;

      if (back == 0) {
        continue;
      } else {
        carry = 1;
        dq.push_front(0);
        for (int i = 1; i < dq.size(); i++) {
          back = dq.back();
          dq.pop_back();
          if (carry == 1 && back == 1) {
            carry = 1;
            dq.push_front(0);
          } else if (carry == 1 && back == 0 || carry == 0 && back == 1) {
            carry = 0;
            dq.push_front(1);
          } else if (carry == 0 && back == 0) {
            dq.push_front(0);
          }
        }
        if (carry == 1) dq.push_front(1);
      }
    }

    return steps;
  }
};