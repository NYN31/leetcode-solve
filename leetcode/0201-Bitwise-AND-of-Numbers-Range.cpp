#include <bits/stdc++.h>
using namespace std;

// 1st Approach
class Solution {
 public:
  int getDecimal(vector<bool> num) {
    int i = num.size() - 1, pos = 0;
    long long dec = 0;
    while (i >= 0) {
      dec += int(num[i--]) * pow(2, pos);
      pos++;
    }
    return dec;
  }
  vector<bool> getBinary(int& num) {
    vector<bool> ans;
    while (num) {
      ans.push_back(num % 2);
      num /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
  int rangeBitwiseAnd(int left, int right) {
    vector<bool> leftBin, rightBin;
    leftBin = getBinary(left);
    rightBin = getBinary(right);

    if (leftBin.size() != rightBin.size()) {
      return 0;
    }

    vector<bool> ansBin;
    int sz = leftBin.size();
    for (int i = 0; i < sz; i++) {
      if (leftBin[i] != rightBin[i])
        break;
      else
        ansBin.push_back(leftBin[i]);
    }
    for (int i = ansBin.size(); i < sz; i++) {
      ansBin.push_back(0);
    }

    return getDecimal(ansBin);
  }
};

// 2nd Approach
int rangeBitwiseAnd(int left, int right) {
  int ans = 0;
  while (left != right) {
    left >>= 1;
    right >>= 1;
    ans++;
  }
  return (left << ans);
}