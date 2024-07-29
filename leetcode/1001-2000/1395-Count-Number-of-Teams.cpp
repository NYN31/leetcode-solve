#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countIncTeams(vector<int>& rating, int currIdx, int teamSz,
                    vector<vector<int>>& inc) {
    if (currIdx == rating.size()) return 0;
    if (teamSz == 3) return 1;

    if (inc[currIdx][teamSz] != -1) return inc[currIdx][teamSz];

    int teams = 0;
    for (int nxtIdx = currIdx + 1; nxtIdx < rating.size(); nxtIdx++) {
      if (rating[nxtIdx] > rating[currIdx]) {
        teams += countIncTeams(rating, nxtIdx, teamSz + 1, inc);
      }
    }

    return inc[currIdx][teamSz] = teams;
  }

  int countDecTeams(vector<int>& rating, int currIdx, int teamSz,
                    vector<vector<int>>& dec) {
    if (currIdx == rating.size()) return 0;
    if (teamSz == 3) return 1;

    if (dec[currIdx][teamSz] != -1) return dec[currIdx][teamSz];

    int teams = 0;
    for (int nxtIdx = currIdx + 1; nxtIdx < rating.size(); nxtIdx++) {
      if (rating[nxtIdx] < rating[currIdx]) {
        teams += countDecTeams(rating, nxtIdx, teamSz + 1, dec);
      }
    }

    return dec[currIdx][teamSz] = teams;
  }

  int numTeams(vector<int>& rating) {
    int n = rating.size();
    int teams = 0;
    vector<vector<int>> inc(n, vector<int>(4, -1)), dec(n, vector<int>(4, -1));

    for (int i = 0; i < n; i++) {
      teams += countIncTeams(rating, i, 1, inc);
      teams += countDecTeams(rating, i, 1, dec);
    }

    return teams;
  }
};