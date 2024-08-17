#include <bits/stdc++.h>
using namespace std;

// Aproach 1: Recursion + DP which got TLE
class Solution {
 public:
  long long fn(int i, int j, int r, int c, vector<vector<int>>& points,
               vector<vector<long long>>& dp) {
    if (i >= r) return 0;

    long long& ans = dp[i][j];
    if (ans != -1) return ans;

    for (int k = 0; k < c; k++) {
      ans =
          max(ans, fn(i + 1, k, r, c, points, dp) + points[i][j] - abs(j - k));
    }

    return ans;
  }

  long long maxPoints(vector<vector<int>>& points) {
    int r = points.size(), c = points[0].size();
    vector<vector<long long>> dp(r, vector<long long>(c, -1LL));

    long long ans = INT_MIN;
    for (int i = 0; i < c; i++) {
      ans = max(ans, fn(0, i, r, c, points, dp));
    }

    return ans;
  }
};

// Aproach 2: Tabulation
class Solution {
 public:
  typedef long long ll;
  int n, m;

  long long maxPoints(vector<vector<int>>& points) {
    n = points.size();
    m = points[0].size();

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

    for (int i = 0; i < m; i++) {
      dp[0][i] = points[0][i];
    }

    for (int i = 1; i < n; i++) {
      vector<ll> leftMax(m), rightMax(m);

      leftMax[0] = dp[i - 1][0];
      for (int j = 1; j < m; j++) {
        leftMax[j] = max(leftMax[j - 1] - 1, dp[i - 1][j]);
      }

      rightMax[m - 1] = dp[i - 1][m - 1];
      for (int j = m - 2; j >= 0; j--) {
        rightMax[j] = max(rightMax[j + 1] - 1, dp[i - 1][j]);
      }

      for (int j = 0; j < m; j++) {
        dp[i][j] = points[i][j] + max(leftMax[j], rightMax[j]);
      }
    }

    ll ans = 0;
    for (int j = 0; j < m; j++) {
      ans = max(ans, dp[n - 1][j]);
    }

    return ans;
  }
};