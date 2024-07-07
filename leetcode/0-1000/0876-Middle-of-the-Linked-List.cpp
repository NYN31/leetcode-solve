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
  ListNode* middleNode(ListNode* head) {
    int len = listLen(head);
    int mid = (len + 1) / 2;
    ListNode* temp = head;
    for (int i = 1; i <= mid - 1; i++) {
      temp = temp->next;
    }
    if (len % 2 == 0) temp = temp->next;
    return temp;
  }
};