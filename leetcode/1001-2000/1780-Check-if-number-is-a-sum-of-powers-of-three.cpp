#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int powerOfThree[16];

  void precal() {
    for (int i = 0; i <= 15; i++) {
      powerOfThree[i] = pow(3, i);
    }
  }

  bool calculateSumOfPowers(int rem, int idx) {
    if(idx > 15) return false;
    if (rem <= 0) {
      return rem == 0;
    }
    return calculateSumOfPowers(rem - powerOfThree[idx], idx + 1) ||
           calculateSumOfPowers(rem, idx + 1);
  }

  bool checkPowersOfThree(int n) {
    precal();
    return calculateSumOfPowers(n, 0);
  }
};