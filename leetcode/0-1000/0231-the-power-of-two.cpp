#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n < 0) return false;
    bitset<32> num(n);
    if (num.count() == 1)
      return true;
    else
      return false;
  }
};