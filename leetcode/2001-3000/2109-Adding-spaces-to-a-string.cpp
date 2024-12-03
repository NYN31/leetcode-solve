#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string addSpaces(string s, vector<int>& spaces) {
    string ans = "", word;
    int prev = 0;

    for (int i = 0; i < spaces.size(); i++) {
      word = s.substr(prev, spaces[i] - prev);
      prev = spaces[i];
      ans += word + ' ';
    }
    ans += s.substr(prev, s.size() - prev);

    return ans;
  }
};