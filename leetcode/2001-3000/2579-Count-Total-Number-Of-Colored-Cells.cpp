#include <bits/stdc++.h>
using namespace std;

// 1st Approach
class Solution {
  vector<long long> oddPrefSum;

  void preCalculatePrefSum(int n) {
    int oddVal = 1;
    oddPrefSum.push_back(0);
    for (int i = 1; i <= n; i++) {
      oddPrefSum.push_back(oddVal);
      oddVal += 2;
    }

    for (int i = 1; i <= n; i++) {
      oddPrefSum[i] = oddPrefSum[i - 1] + oddPrefSum[i];
    }
  }

 public:
  long long coloredCells(int n) {
    preCalculatePrefSum(n);
    return oddPrefSum[n] + oddPrefSum[n - 1];
  }
};

// Second Approach
class Solution {
 public:
  long long coloredCells(int n) {
    long long ans = 0, oddVal = 1;
    for (int i = 1; i < n; i++) {
      ans += oddVal;
      oddVal += 2;
    }

    ans = ans + ans + oddVal;
    return ans;
  }
};