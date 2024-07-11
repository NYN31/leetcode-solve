#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string reverseParentheses(string s) {
    deque<char> dq;
    for (char ch : s) {
      if (ch == ')') {
        string reversedStr;
        while (!dq.empty()) {
          char top = dq.back();
          dq.pop_back();
          if (top == '(') {
            break;
          }
          reversedStr += top;
        }
        for (char c : reversedStr) {
          dq.push_back(c);
        }
      } else {
        dq.push_back(ch);
      }
    }
    return string(dq.begin(), dq.end());
  }
};