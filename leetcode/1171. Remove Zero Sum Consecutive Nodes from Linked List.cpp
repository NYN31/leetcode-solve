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
  ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* start = head;
    while (start) {
      ListNode* end = start->next;
      int sum = 0;
      while (end) {
        sum += end->val;
        if (sum == 0) break;
        end = end->next;
      }
      if (sum == 0) {
        if (start == head)
          head = end->next;
        else
          prev = end->next;

        start = head;
      } else {
        prev = start;
        start = start->next;
      }
    }
    return head;
  }
};