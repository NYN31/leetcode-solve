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
  ListNode* reverse(ListNode* head) {
    ListNode *curr = head, *nxt = nullptr, *prev = nullptr;

    while (curr) {
      nxt = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nxt;
    }

    return prev;
  }

  void remove(ListNode* reversedList) {
    ListNode *curr = reversedList, *prv = nullptr;
    int mx = -1;
    while (curr) {
      if (curr->val >= mx) {
        mx = curr->val;
        prv = curr;
      } else {
        prv->next = curr->next;
      }

      curr = curr->next;
    }
  }

  ListNode* removeNodes(ListNode* head) {
    ListNode* reversedList = reverse(head);
    remove(reversedList);
    return reverse(reversedList);
  }
};