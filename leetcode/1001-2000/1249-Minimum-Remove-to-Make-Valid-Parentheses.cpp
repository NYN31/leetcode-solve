#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    stack<int> st;
    string ans = "";

    for (int i = 0; i < s.size(); i++) {
      if (st.empty() && (s[i] == '(' || s[i] == ')'))
        st.push(i);
      else if (!st.empty() && (s[i] == '(' || s[i] == ')')) {
        int top = st.top();
        if (top == '(' && s[i] == ')')
          st.pop();
        else
          st.push(i);
      }
    }

    int i = s.size() - 1;
    while (i >= 0) {
      if (st.empty()) {
        ans += s[i];
      } else {
        int top = st.top();
        while (i >= 0) {
          if (i == top) {
            break;
          }
          ans += s[i];
          i--;
        }
        st.pop();
      }
      i--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};