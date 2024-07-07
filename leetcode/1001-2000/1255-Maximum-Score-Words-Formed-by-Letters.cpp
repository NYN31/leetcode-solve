#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxScoreWords(vector<string>& words, vector<char>& letters,
                    vector<int>& score) {
    int w = words.size();
    int l = letters.size();

    int cnt[26] = {0};
    for (int i = 0; i < l; ++i) cnt[letters[i] - 'a'] += 1;

    int ans = 0;
    for (int comb = 1; comb < (1 << w); ++comb) {
      int currScore = 0;
      bool isValid = true;
      int curr[26] = {0};
      for (int i = 0; i < w; ++i) {
        if (!((1 << i) & comb)) continue;
        for (int j = 0; j < words[i].length(); ++j) {
          char ch = words[i][j];
          curr[ch - 'a'] += 1;
          currScore += score[ch - 'a'];
          if (curr[ch - 'a'] > cnt[ch - 'a']) isValid = false;
        }
      }
      if (isValid) ans = max(ans, currScore);
    }
    return ans;
  }
};