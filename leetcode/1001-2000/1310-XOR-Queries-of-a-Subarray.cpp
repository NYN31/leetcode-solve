#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> ans, fp;

    fp.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++) {
      fp.push_back(fp[i - 1] ^ arr[i]);
    }



    for (auto& q : queries) {
      int l = q[0], r = q[1];
      if (l == 0)
        ans.push_back(fp[r]);
      else
        ans.push_back(fp[r] ^ fp[l - 1]);
    }

    return ans;
  }
};