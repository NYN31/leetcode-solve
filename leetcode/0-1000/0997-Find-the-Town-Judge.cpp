/*
 * Title: Leetcode Problem
 * Description: Leetcode Daily Problem solve
 * Author: Md Sajjad Hosen Noyon
 * Handle: NOYON31
 * Date: 22/02/2024
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> ind(n + 1, 0), outd(n + 1, 0);
    for (auto& pr : trust) {
      ind[pr[1]]++;
      outd[pr[0]]++;
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
      if (ind[i] == n - 1 && outd[i] == 0) {
        return i;
      }
    }
    return ans;
  }
};
