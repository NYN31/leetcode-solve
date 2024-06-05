#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<string> commonChars(vector<string>& words) {
    string first = words[0];
    vector<char> hash(26, 0);
    vector<string> ans;

    for (char& ch : first) {
      if (hash[ch - 'a']) continue;
      int maxCnt = 0, minCnt = INT_MAX;
      for (int i = 0; i < words.size(); i++) {
        int curr_cnt = 0;
        for (char& ch_in : words[i]) {
          if (ch_in == ch) curr_cnt += 1;
        }
        maxCnt = max(maxCnt, curr_cnt);
        minCnt = min(minCnt, curr_cnt);
      }
      cout << ch << " " << minCnt << " " << maxCnt << endl;
      if (minCnt > 0) {
        for (int i = 0; i < minCnt; i++) {
          ans.push_back(string(1, ch));
        }
      }
      hash[ch - 'a'] = 1;
    }

    return ans;
  }
};