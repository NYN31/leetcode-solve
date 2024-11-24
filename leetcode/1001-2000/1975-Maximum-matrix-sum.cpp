#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long maxMatrixSum(vector<vector<int>>& matrix) {
    int mn = INT_MAX;
    long long sum = 0;
    bool isEven = true;

    for (auto& row : matrix) {
      for (int num : row) {
        if (num < 0) {
          isEven = !isEven;
          num = num * -1;
        }
        mn = min(mn, num);
        sum += num;
      }
    }

    return isEven ? sum : sum - (mn + mn);
  }
};