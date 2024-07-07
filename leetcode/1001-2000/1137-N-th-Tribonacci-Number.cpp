#include <bits/stdc++.h>
using namespace std;

class Solution {
  int dp[40];
  int fn(int n) {
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 1;
    int& ans = dp[n];
    if (ans != -1) return ans;
    ans = fn(n - 1) + fn(n - 2) + fn(n - 3);
    return ans;
  }

 public:
  int tribonacci(int n) {
    memset(dp, -1, sizeof dp);
    return fn(n);
  }
};