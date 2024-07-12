#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findPoints1(string& s, string& s1, int& point, stack<char>& stk) {
    int cnt = 0;
    string curr = "";

    for (auto& ch : s) {
      if (stk.empty()) {
        stk.push(ch);
      } else {
        curr = "";
        curr.push_back(stk.top());
        curr.push_back(ch);
        if (curr == s1) {
          cnt += point;
          stk.pop();
        } else
          stk.push(ch);
      }
    }

    return cnt;
  }

  int findPoints2(string& s, string& s1, int& point, stack<char>& stk) {
    string curr = "";
    while (!stk.empty()) {
      curr.push_back(stk.top());
      stk.pop();
    }
    reverse(curr.begin(), curr.end());
    return findPoints1(curr, s1, point, stk);
  }

  int maximumGain(string s, int x, int y) {
    stack<char> stk;
    string ab = "ab", ba = "ba";

    int points1 = findPoints1(s, ab, x, stk) + findPoints2(s, ba, y, stk);
    stk = stack<char>();
    int points2 = findPoints1(s, ba, y, stk) + findPoints2(s, ab, x, stk);

    return max(points1, points2);
  }
};