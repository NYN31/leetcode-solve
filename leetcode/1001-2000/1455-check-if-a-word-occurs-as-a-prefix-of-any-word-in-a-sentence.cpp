#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int isPrefixOfWord(string sen, string searchWord) {
    int indx = 1;
    string word;

    stringstream ss(sen);

    while (ss >> word) {
      int len = searchWord.size();
      if (word.substr(0, len) == searchWord) {
        return indx;
      }
      indx += 1;
    }

    return -1;
  }
};