#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestOnes(vector<int>& nums, int k) {
    int mxL = 0, l = 0, r = 0, n = nums.size() - 1;
    if (nums[0] == 0) k--;

    while (l < n && r < n) {
      while (k >= 0 && r < n) {
        r++;
        if (nums[r] == 0) k--;
        if(k == 0) mxL = max(mxL, r - l + 1);
      }
      cout << l << " " << r << " " << k << endl;
      while (k < 0 && l <= r) {
        if (nums[l] == 0) k++;
        l++;
        if(k == 0) mxL = max(mxL, r - l + 1);
      }
    }
    return mxL;
  }
};

int main() {
  int n;
  cout << "Enter student number: ";
  cin >> n;

  Student student[n];

  for (int i = 0; i < n; i++) {
    student[i].getDetails();
  }

  for (int i = 0; i < n; i++) {
    student[i].printDetails();
  }

  return 0;
}