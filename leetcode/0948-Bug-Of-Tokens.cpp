#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());
    if (tokens.size() == 0 || tokens[0] > power) return 0;

    int score = 0, lo = 0, hi = tokens.size() - 1;
    while (lo <= hi) {
      if (lo == hi) {
        if (power >= tokens[lo])
          score++, power -= tokens[lo++];
        else
          power += tokens[hi--];
      } else if (tokens[lo] <= power)
        score++, power -= tokens[lo++];
      else
        score--, power += tokens[hi--];
    }
    return score;
  }
};