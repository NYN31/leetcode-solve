#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int timeRequiredToBuy(vector<int>& tickets, int k) {
    int times = 0;
    for (int i = 0; i < tickets.size(); i++) {
      cout << tickets[i] << " ";
      if (tickets[i] < tickets[k])
        times += tickets[i];
      else if (tickets[i] > tickets[k])
        times += tickets[k] - (i > k);
      else {
        if (i <= k)
          times += tickets[k];
        else
          times += tickets[k] - 1;
      }
    }
    return times;
  }
};