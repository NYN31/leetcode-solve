#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minimumRecolors(string blocks, int k) {
    int w = 0, b = 0, ans = 10000000;

    for (int i = 0; i < k; i++) {
      if (blocks[i] == 'W') w += 1;
      else b += 1;
    }

    int i = 0, j = k - 1;
    while (j < blocks.size()) {
      ans = min(ans, w);

      if (blocks[i] == 'W') w -= 1;
      else b -= 1;
      i++, j++;
      if (blocks[j] == 'W') w += 1;
      else b += 1;
    }

    return ans;
  }
};