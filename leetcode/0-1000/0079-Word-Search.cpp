#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int row, col;
  bool fn(int idx, int r, int c, vector<vector<char>>& board, string& word) {
    if (idx == word.size()) return true;
    if (r < 0 || r == row || c < 0 || c == col || board[r][c] == '.') {
      return false;
    }

    bool exist = false;
    if (board[r][c] == word[idx]) {
      char prev = board[r][c];
      board[r][c] = '.';

      exist = fn(idx + 1, r + 1, c, board, word) ||
              fn(idx + 1, r - 1, c, board, word) ||
              fn(idx + 1, r, c + 1, board, word) ||
              fn(idx + 1, r, c - 1, board, word);
      board[r][c] = prev;
    }

    return exist;
  }

  bool exist(vector<vector<char>>& board, string word) {
    row = board.size(), col = board[0].size();
    if (word.size() > row * col) return false;

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (fn(0, i, j, board, word)) {
          return true;
        }
      }
    }
    return false;
  }
};