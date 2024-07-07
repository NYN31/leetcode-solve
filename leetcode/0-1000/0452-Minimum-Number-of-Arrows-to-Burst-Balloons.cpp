#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static bool cmp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), cmp);
    int arrows = 1, first = points[0][0], second = points[0][1];
    for (int i = 1; i < points.size(); i++) {
      if (points[i][1] >= second && points[i][0] <= second) {
        second = min(second, points[i][1]);
      } else {
        arrows += 1;
        second = points[i][1];
      }
    }
    return arrows;
  }
};