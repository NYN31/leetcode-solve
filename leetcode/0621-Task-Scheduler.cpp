#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    unordered_map<int, int> freq;
    int mxFreq = -1e9, totalCycle = 0;
    for (auto& task : tasks) {
      freq[task]++;
      mxFreq = max(mxFreq, freq[task]);
    }
    for (auto& [_, value] : freq) {
      if (value == mxFreq) {
        totalCycle += 1;
      }
    }
    int intervals = totalCycle * mxFreq;
    intervals += ((n + 1) - totalCycle) * (mxFreq - 1);

    return max(intervals, (int)tasks.size());
  }
};
