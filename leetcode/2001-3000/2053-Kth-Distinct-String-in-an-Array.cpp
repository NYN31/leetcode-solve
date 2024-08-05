#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string kthDistinct(vector<string>& arr, int k) {
    unordered_map<string, int> hash;

    for (auto& s : arr) hash[s]++;

    int cnt = 1;
    string ans = "";
    for (auto& s : arr) {
      if (hash[s] == 1) {
        if (cnt == k) {
          ans = s;
          break;
        } else cnt++;
      }
    }
    return ans;
  }
};