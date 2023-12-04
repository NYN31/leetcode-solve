class Solution
{
public:
    const int mod = 1e9 + 7;
    long long dp[5005][5005];
    vector<vector<int>> pos{
        {6, 4}, {6, 8}, {4, 7}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {3, 1}, { 2, 4 }
    };

    long long fn(int n, int d) {
      if(n == 0) return 1;
      long long &ans = dp[n][d];
      if(ans != -1) return ans;
      vector<int>& dis = pos[d];
      for(int i=0; i<dis.size(); i++) {
        ans = (ans + fn(n - 1, dis[i])) % mod;
      }
      return ans;
    }

    int knightDialer(int n) {
      memset(dp, -1, sizeof dp);
      long long total = 0;
      for(int i = 0; i < 9; i++) {
        total = (total + fn(n - 1, i)) % mod;
      }
      return total;
    }

    int main()
};