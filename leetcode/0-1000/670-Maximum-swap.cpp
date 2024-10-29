#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maximumSwap(int num) {
    vector<int> dig;

    int newNum = num;

    while (newNum) {
      dig.push_back(newNum % 10);
      newNum /= 10;
    }

    for (int i = dig.size() - 1; i > 0; --i) {
      if (dig[i] < dig[i - 1]) {
        swap(dig[i], dig[i - 1]);
        break;
      }
    }


    for (int i = dig.size() - 1; i >= 0; --i) {
      newNum = newNum * 10 + dig[i];
    }

    return newNum;
  }
};