#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> ans;
    vector<int> hash(10, 0);

    for (auto& digit : digits) hash[digit] += 1;

    for (int i = 100; i <= 998; i += 2) {
      int a, b, c;
      a = i % 10;
      b = (i / 10) % 10;
      c = (i / 100) % 10;

      if (a == b && b == c && hash[a] < 3)
        continue;
      else if (a == b && b != c && hash[a] < 2 ||
               b == c && a != b && hash[b] < 2 ||
               a == c && a != b && hash[a] < 2)
        continue;
      else if (hash[a] < 1 || hash[b] < 1 || hash[c] < 1)
        continue;

      ans.push_back(i);
    }

    return ans;
  }
};