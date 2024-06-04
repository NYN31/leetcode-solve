#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void store(vector<int>& hash, char ch) {
    if (ch >= 'A' && ch <= 'Z')
      hash[ch - 'A']++;
    else
      hash[ch - 'a' + 26]++;
  }

  int longestPalindrome(string s) {
    vector<int> hash(52, 0);

    for (int i = 0; i < s.size(); i++) {
      store(hash, s[i]);
    }

    int even = 0, odd = 0, maxOdd = 0;
    for (int i = 0; i < 52; i++) {
      if (hash[i] % 2 == 1) {
        maxOdd = max(maxOdd, hash[i]);
        odd += hash[i] - 1;
      } else {
        even += hash[i];
      }
    }

    return even + odd + (maxOdd >= 1);
  }
};