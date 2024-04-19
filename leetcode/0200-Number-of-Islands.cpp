#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int row, col;

  void bfs(int srcX, int srcY, vector<vector<char>>& grid,
           vector<vector<bool>>& visited) {
    queue<pair<int, int>> qu;
    vector<int> dRow{0, 1, 0, -1};
    vector<int> dCol{-1, 0, 1, 0};

    qu.push({srcX, srcY});
    visited[srcX][srcY] = true;

    while (!qu.empty()) {
      pair<int, int> top = qu.front();
      qu.pop();

      for (int i = 0; i < 4; i++) {
        int x = top.first + dRow[i];
        int y = top.second + dCol[i];

        if (x >= 0 && y >= 0 && x <= row && y <= col &&
            visited[x][y] == false && grid[x][y] == '1') {
          qu.push({x, y});
          visited[x][y] = true;
        }
      }
    }
  }

  int numIslands(vector<vector<char>>& grid) {
    row = grid.size() - 1;
    col = grid[0].size() - 1;
    vector<vector<bool>> visited(row + 1, vector<bool>(col + 1, false));
    int iLand = 0;

    for (int i = 0; i <= row; i++) {
      for (int j = 0; j <= col; j++) {
        if (!visited[i][j] && grid[i][j] == '1') {
          iLand += 1;
          bfs(i, j, grid, visited);
        }
      }
    }

    return iLand;
  }
};