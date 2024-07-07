#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool checkSameLater(char ch1, char ch2) {
    if (ch1 >= 'A' && ch1 <= 'Z') return ch1 + 32 == ch2;
    return ch1 == ch2 + 32;
  }

 public:
  string makeGood(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
      if (st.empty())
        st.push(s[i]);
      else {
        char top = st.top();
        if (checkSameLater(top, s[i])) {
          st.pop();
        } else {
          st.push(s[i]);
        }
      }
    }
    s = "";
    while (!st.empty()) {
      char top = st.top();
      s += top;
      st.pop();
    }
    reverse(s.begin(), s.end());

    return s;
  }
};