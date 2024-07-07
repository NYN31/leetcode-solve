#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  bool isCriticalPoint(int& prev, int& curr, int& nxt) {
    if (curr > prev && curr > nxt)
      return true;
    else if (curr < prev && curr < nxt)
      return true;
    else
      return false;
  }

  // 1st approach
  vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    if (head->next->next == nullptr) return {-1, -1};
    ListNode *curr = head->next, *prev = head;
    vector<int> c_points, ans(2);
    int idx = 2;

    while (curr && curr->next) {
      if (isCriticalPoint(prev->val, curr->val, curr->next->val)) {
        c_points.push_back(idx);
      }
      idx += 1;
      prev = curr;
      curr = curr->next;
    }

    int len = c_points.size();
    if (len == 1) return {-1, -1};

    int mnDis = INT_MAX, mxDis = c_points[len - 1] - c_points[0];
    for (int i = 1; i < len; i++) {
      mnDis = min(mnDis, c_points[i] - c_points[i - 1]);
    }

    return {mnDis, mxDis};
  }

  // second approach
  vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    ListNode *curr = head->next, *prev = head;
    int idx = 2, start = -1, end = -1;

    int mnDis = INT_MAX, mxDis;
    while (curr && curr->next) {
      if (isCriticalPoint(prev->val, curr->val, curr->next->val)) {
        if (start == -1) start = idx;
        if (start < idx) mnDis = min(mnDis, idx - end);
        end = idx;
      }
      idx += 1;
      prev = curr;
      curr = curr->next;
    }

    if (start == end) return {-1, -1};
    mxDis = end - start;
    return {mnDis, mxDis};
  }
};