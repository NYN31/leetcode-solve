#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int heightChecker(vector<int>& heights) {
    vector<int> required;
    for (auto& height : heights) required.push_back(height);
    sort(required.begin(), required.end());

    int cnt = 0;
    for (int i = 0; i < heights.size(); i++) {
      if (heights[i] != required[i]) {
        cnt += 1;
      }
    }

    return cnt;
  }
};