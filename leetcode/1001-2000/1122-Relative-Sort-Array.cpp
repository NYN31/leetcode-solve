#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> mySort(map<int, int>& hash, vector<int>& arr) {
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++) {
      int countVal = hash[arr[i]];
      for (int j = 0; j < countVal; j++) {
        ans.push_back(arr[i]);
      }
      hash.erase(arr[i]);
    }

    for (auto& [key, value] : hash) {
      if (value > 0) {
        for (int i = 0; i < value; i++) {
          ans.push_back(key);
        }
      }
    }

    return ans;
  }
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    map<int, int> hash;
    for (int i = 0; i < arr1.size(); i++) {
      hash[arr1[i]] += 1;
    }

    return mySort(hash, arr2);
  }
};