#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dp[105][105];

int fn(int i, int j, int& sz, vector<vector<int>>& mat) {
  if (i > sz || j > sz || j < 0) return 0;
  int& ans = dp[i][j];
  if (ans != -1) return ans;

  ans = fn(i + 1, j, sz, mat) + mat[i][j];
  ans += fn(i + 1, j - 1, sz, mat) + mat[i][j];
  ans += fn(i + 1, j + 1, sz, mat) + mat[i][j];

  return ans;
}

int minFallingPathSum(vector<vector<int>>& matrix) {
  memset(dp, -1, sizeof dp);
  int n = int(matrix.size());
  int ans = -1e9;
  for (int i = 0; i < n; i++) {
    ans = max(ans, fn(0, i, n, matrix));
  }
  return ans;
}

void solve() {
  int n;
  vector<vector<int>> arr(n);
  cin >> n;
  for (int i = 0; i < n; i++) {
    vector<int> inner(n);
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      inner.push_back(a);
    }
    arr.push_back(inner);
  }
  minFallingPathSum(arr);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}