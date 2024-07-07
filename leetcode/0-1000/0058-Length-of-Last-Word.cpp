#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int lengthOfLastWord(string s) {
    string last = "";
    int len = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        if (last.size() > 0) len = last.size();
        last = "";
      } else
        last.push_back(s[i]);
    }
    if (last.size() > 0) len = last.size();
    return len;
  }
};