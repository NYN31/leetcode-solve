#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minOperationsUsingStack(vector<string>& logs) {
    stack<string> st;
    for (int i = 0; i < logs.size(); i++) {
      if (logs[i] == "./") {
      } else if (logs[i] == "../") {
        if (!st.empty()) {
          st.pop();
        }
      } else {
        st.push(logs[i]);
      }
    }

    return st.size();
  }

  int minOperations(vector<string>& logs) {
    int cnt = 0;
    for (auto& currentLogs : logs) {
      if (currentLogs == "../") {
        cnt = max(0, cnt - 1);
      } else if (currentLogs != "./") {
        cnt += 1;
      }
    }

    return cnt;
  }
};