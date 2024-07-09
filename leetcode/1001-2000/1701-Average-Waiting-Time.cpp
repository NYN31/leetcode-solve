#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  double averageWaitingTime(vector<vector<int>>& customers) {
    long long start = 0, end = 0, waiting = 0;

    for (int i = 0; i < customers.size(); i++) {
      vector<int> customer = customers[i];

      start = customer[0];
      end = max(start, end) + customer[1];
      waiting += end - customer[0];
    }

    return (waiting * 1.0) / customers.size();
  }
};