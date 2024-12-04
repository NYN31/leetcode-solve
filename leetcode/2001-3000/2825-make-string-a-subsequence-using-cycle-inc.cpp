#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
    bool canMakeSubsequence(string str1, string str2) {
    if (str2.size() > str1.size()) return false;

    int i = str1.size() - 1, j = str2.size() - 1;
    while (i >= 0 && j >= 0) {
      if (str1[i] == str2[j]) {
        i--;
        j--;
      } else if (str1[i] == 'z' && str2[j] == 'a') {
        i--;
        j--;
      } else if (str2[j] - str1[i] == 1) {
        i--;
        j--;
      } else
        i--;
    }

    if (j < 0) return true;
    return false;
  }
};