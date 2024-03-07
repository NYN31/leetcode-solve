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
  int listLen(ListNode* head) {
    int cnt = 0;
    while (head) {
      cnt++;
      head = head->next;
    }
    return cnt;
  }
  ListNode* deleteMiddle(ListNode* head) {
    int len = listLen(head);
    int mid = len / 2;
    if (len == 1) return NULL;

    ListNode* temp = head;
    for (int i = 1; i < mid; i++) {
      temp = temp->next;
    }
    if (temp->next->next)
      temp->next = temp->next->next;
    else
      temp->next = NULL;

    return head;
  }
};