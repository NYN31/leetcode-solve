#include <bits/stdc++.h>
using namespace std;

class Solution {
  void myPush(int idx, vector<int>& students) {
    int temp = students[idx];
    for (int i = idx + 1; i < students.size(); i++) {
      students[i - 1] = students[i];
    }
    students[students.size() - 1] = temp;
  }

 public:
  int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int sandwichesLoverCount[2] = {0}, ans = 0;
    for (int i = 0; i < students.size(); i++) {
      sandwichesLoverCount[students[i]]++;
    }
    for (int i = 0, j = 0; i < students.size();) {
      if (students[i] == sandwiches[j]) {
        sandwichesLoverCount[students[i]]--;
        i++, j++;
      } else {
        if (sandwichesLoverCount[sandwiches[j]] <= 0) {
          ans = students.size() - i;
          break;
        } else {
          if (i + 1 < students.size())
            myPush(i, students);
          else {
            ans = 1;
            break;
          }
        }
      }
    }

    return ans;
  }
};