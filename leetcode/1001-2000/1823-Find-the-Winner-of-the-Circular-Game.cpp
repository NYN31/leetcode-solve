#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findTheWinner(int n, int k) {
    deque<int> friends;
    for (int i = 1; i <= n; i++) friends.push_back(i);

    int idx = 1;
    while (friends.size() != 1) {
      int f = friends.front();
      friends.pop_front();
      if (idx != k) {
        friends.push_back(f);
        idx = 1;
      } else {
        idx += 1;
      }
    }

    return friends.front();
  }
};