class Solution {
 public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> psa(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        psa[i][j] = matrix[i - 1][j - 1] + psa[i - 1][j] + psa[i][j - 1] -
                    psa[i - 1][j - 1];
      }
    }

    int cnt = 0;
    for (int toRow = 1; toRow <= m; toRow++) {
      for (int toCol = 1; toCol <= n; toCol++) {
        for (int fromRow = 1; fromRow <= toRow; fromRow++) {
          for (int fromCol = 1; fromCol <= toCol; fromCol++) {
            int s = psa[toRow][toCol] - psa[fromRow - 1][toCol] -
                    psa[toRow][fromCol - 1] + psa[fromRow - 1][fromCol - 1];
            if (s == target) cnt += 1;
          }
        }
      }
    }

    return cnt;
  }
};