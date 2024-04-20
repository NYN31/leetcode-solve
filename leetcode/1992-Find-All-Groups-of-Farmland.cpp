#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int row, col;

  pair<int, int> bfs(int srcX, int srcY, vector<vector<int>>& land) {
    queue<pair<int, int>> qu;
    vector<int> dRow{0, 1, 0, -1};
    vector<int> dCol{-1, 0, 1, 0};
    int mxSum = srcX + srcY, mxX = srcX, mxY = srcY;

    qu.push({srcX, srcY});
    land[srcX][srcY] = 0;

    while (!qu.empty()) {
      pair<int, int> top = qu.front();
      qu.pop();

      for (int i = 0; i < 4; i++) {
        int x = top.first + dRow[i];
        int y = top.second + dCol[i];

        if (x >= 0 && y >= 0 && x <= row && y <= col && land[x][y] == 1) {
          qu.push({x, y});
          land[x][y] = 0;
          if (x + y > mxSum) {
            mxSum = x + y;
            mxX = x, mxY = y;
          }
        }
      }
    }

    return {mxX, mxY};
  }

  vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    row = land.size() - 1;
    col = land[0].size() - 1;
    vector<vector<int>> ans;
    
    for (int i = 0; i <= row; i++) {
      for (int j = 0; j <= col; j++) {
        if (land[i][j] == 1) {
          pair<int, int> pr = bfs(i, j, land);
          ans.push_back({i, j, pr.first, pr.second});
        }
      }
    }

    return ans;
  }
};