class Solution {
 public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    map<int, int> onlyWinners;
    vector<vector<int>> ans(2, vector<int>());

    for (auto& match : matches) {
      onlyWinners[match[0]] = 1;
    }
    for (auto& match : matches) {
      if (onlyWinners[match[1]] > 0) onlyWinners[match[1]] = 0;
      onlyWinners[match[1]] -= 1;
    }

    for (auto& [key, value] : onlyWinners) {
      if (value > 0)
        ans[0].push_back(key);
      else if (value == -1)
        ans[1].push_back(key);
    }

    return ans;
  }
};