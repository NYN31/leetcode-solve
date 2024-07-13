#include <bits/stdc++.h>
using namespace std;

// copy & paste
class Solution {
  int isForward(char direction) {
    if (direction == 'R') {
      return 1;
    }
    return 0;
  }

  static bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
    return p1.second < p2.second;
  }

 public:
  vector<int> survivedRobotsHealths(vector<int> &positions,
                                    vector<int> &healths, string directions) {
    map<int, vector<int>> mp;
    for (int i = 0; i < positions.size(); i++) {
      //                 {health, direction, index}
      mp[positions[i]] = {healths[i], isForward(directions[i]), i};
    }
    stack<vector<int>> stck;
    vector<pair<int, int>> safe;
    for (auto &it : mp) {
      if (it.second[1]) {
        stck.push(it.second);
      } else {
        if (stck.empty()) {
          safe.push_back({it.second[0], it.second[2]});
        } else {
          vector<int> winner = it.second;
          while (!stck.empty()) {
            vector<int> top = stck.top();
            stck.pop();
            if (top[0] > winner[0]) {
              top[0]--;
              stck.push(top);
              winner.clear();
              break;
            } else if (top[0] == winner[0]) {
              winner.clear();
              break;
            }
            winner[0]--;
          }
          if (!winner.empty()) {
            safe.push_back({winner[0], winner[2]});
          }
        }
      }
    }
    while (!stck.empty()) {
      safe.push_back({stck.top()[0], stck.top()[2]});
      stck.pop();
    }
    sort(safe.begin(), safe.end(), cmp);
    vector<int> ans;
    for (auto &health : safe) {
      ans.push_back(health.first);
    }
    return ans;
  }
};