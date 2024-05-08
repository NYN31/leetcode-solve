#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<string> findRelativeRanks(vector<int>& score) {
    map<int, string, greater<int>> hash;
    vector<string> result;

    for (int i = 0; i < score.size(); i++) {
      hash[score[i]] = "";
    }

    int rank = 1;
    for (auto& [key, value] : hash) {
      if (rank == 1) {
        hash[key] = "Gold Medal";
      } else if (rank == 2) {
        hash[key] = "Silver Medal";
      } else if (rank == 3) {
        hash[key] = "Bronze Medal";
      } else {
        hash[key] = to_string(rank);
      }
      rank += 1;
    }

    for (int i = 0; i < score.size(); i++) {
      result.push_back(hash[score[i]]);
    }

    return result;
  }
};