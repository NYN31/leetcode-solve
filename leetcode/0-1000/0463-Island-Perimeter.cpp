#include <bits/stdc++.h>
using namespace std;

class Solution {
  int row, col;

 public:
  int bfs(int i, int j, vector<vector<int>>& grid,
          vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    vector<int> dRow{0, 1, 0, -1};
    vector<int> dCol{-1, 0, 1, 0};

    q.push({i, j});
    visited[i][j] = true;
    int cnt = 0;

    while (!q.empty()) {
      pair<int, int> top = q.front();
      q.pop();
      int u = top.first, v = top.second;

      for (int i = 0; i < 4; i++) {
        int x = u + dRow[i];
        int y = v + dCol[i];

        if (x < 0 || y < 0 || x > row || y > col) {
          cnt++;
          continue;
        }

        if (grid[x][y] == 1 && visited[x][y] == false) {
          q.push({x, y});
          visited[x][y] = true;
        } else if (grid[x][y] == 0) {
          cnt += 1;
        }
      }
    }

    return cnt;
  }

  int islandPerimeter(vector<vector<int>>& grid) {
    row = grid.size() - 1;
    col = grid[0].size() - 1;
    vector<vector<bool>> visited(row + 1, vector<bool>(col + 1, false));
    int ans = 0;
    bool flag = false;

    for (int i = 0; i <= row; i++) {
      for (int j = 0; j <= col; j++) {
        if (grid[i][j] == 1) {
          ans = bfs(i, j, grid, visited);
          flag = true;
        }
        if (flag) break;
      }
      if (flag) break;
    }

    return ans;
  }
};