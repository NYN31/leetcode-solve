#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool checkIfExist(vector<int>& arr) {
    unordered_map<int, int> hash;
    for (auto& num : arr) {
      int half = num / 2;
      int dbl = num * 2;

      if (!(num & 1) && hash.find(half) != hash.end()) return true;
      if (hash.find(dbl) != hash.end()) return true;
      hash[num] = true;
    }

    return false;
  }
};