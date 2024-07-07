#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    vector<pair<double, vector<int>>> hash;
    double mn = 1e9;
    for (int i = 0; i < arr.size() - 1; i++) {
      for (int j = i + 1; j < arr.size(); j++) {
        double res = arr[i] / (arr[j] * 1.0);
        hash.push_back({res, {arr[i], arr[j]}});
      }
    }
    sort(hash.begin(), hash.end());

    return hash[k - 1].second;
  }
};