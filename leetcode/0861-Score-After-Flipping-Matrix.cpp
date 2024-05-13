#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int matrixScore(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    for (int row = 0; row < m; row++) {
      if (grid[row][0] == 0) {
        for (int col = 0; col < n; col++) {
          grid[row][col] = !grid[row][col];
        }
      }
    }

    for (int col = 1; col < n; col++) {
      int zeroCount = 0;
      for (int row = 0; row < m; row++) {
        zeroCount += grid[row][col] ? 0 : 1;
      }
      if (zeroCount >= (m + 1) / 2) {
        for (int row = 0; row < m; row++) {
          grid[row][col] = !grid[row][col];
        }
      }
    }

    int sum = 0;
    for (int i = 0; i < m; i++) {
      int power = 0;
      for (int j = n - 1; j >= 0; --j) {
        sum += (grid[i][j] * pow(2, power));
        power += 1;
      }
    }

    return sum;
  }
};