#include <bits/stdc++.h>
using namespace std;

class Solution {
  string myPush(string& curr, int& times, char& ch) {
    for (int i = 1; i <= times; i++) curr.push_back(ch);
    return curr;
  }

 public:
  string customSortString(string order, string s) {
    vector<int> frq(26, 0);
    string curr = "";
    for (auto& ch : s) frq[ch - 'a']++;
    for (auto& ch : order) {
      int times = frq[ch - 'a'];
      if (times > 0) {
        curr = myPush(curr, times, ch);
        frq[ch - 'a'] = 0;
      }
    }
    for (int i = 0; i < 26; i++) {
      char ch = char(i + 'a');
      curr = myPush(curr, frq[i], ch);
    }
    return curr;
  }
};