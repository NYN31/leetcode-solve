#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());

    int lo = 0, hi = people.size() - 1, boats = 0;
    while (lo <= hi) {
      boats += 1;
      if (lo == hi)
        break;
      else if (people[lo] + people[hi] <= limit) {
        lo += 1, hi -= 1;
      } else
        hi -= 1;
    }

    return boats;
  }
};