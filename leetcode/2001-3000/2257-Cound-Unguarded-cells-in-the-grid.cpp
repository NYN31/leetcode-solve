#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countUnguarded(int m, int n, vector<vector<int>>& guards,
                     vector<vector<int>>& walls) {
    int empty = 0, guard = 1, wall = 2, seen = 3;
    vector<vector<int>> visited(m,
                                vector<int>(n, empty));  // 0 means empty cell

    for (int i = 0; i < guards.size(); i++) {
      visited[guards[i][0]][guards[i][1]] = guard;  // 1 means guard
    }

    for (int i = 0; i < walls.size(); i++) {
      visited[walls[i][0]][walls[i][1]] = wall;  // 2 means wall
    }

    // 3 means seen cell
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (visited[i][j] == wall || visited[i][j] == seen) continue;

        if (visited[i][j] == guard) {
          // buttom
          for (int k = i + 1; k < m; k++) {
            if (visited[k][j] == empty || visited[k][j] == seen)
              visited[k][j] = seen;
            else
              break;
          }
          // up
          for (int k = i - 1; k >= 0; k--) {
            if (visited[k][j] == empty || visited[k][j] == seen)
              visited[k][j] = seen;
            else
              break;
          }
          // right
          for (int k = j + 1; k < n; k++) {
            if (visited[i][k] == empty || visited[i][k] == seen)
              visited[i][k] = seen;
            else
              break;
          }
          // left
          for (int k = j - 1; k >= 0; k--) {
            if (visited[i][k] == empty || visited[i][k] == seen)
              visited[i][k] = seen;
            else
              break;
          }
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (visited[i][j] == empty) {
          ans += 1;
        }
      }
    }

    return ans;
  }
};