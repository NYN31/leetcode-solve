#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Aproach 1
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
  ListNode* doubleIt(ListNode* head) {
    ListNode* reverseList = reverse(head);

    ListNode* curr = reverseList;
    int rem = 0;
    while (true) {
      int d = (curr->val * 2) + rem;
      rem = d / 10;
      curr->val = d % 10;
      if (!curr->next) break;
      curr = curr->next;
    }

    if (rem > 0) {
      ListNode* newNode = new ListNode(rem);
      curr->next = newNode;
    }
    return reverse(reverseList);
  }
};

// Approach 2
class Solution {
 public:
  ListNode* doubleIt(ListNode* head) {
    ListNode *curr = nullptr, *newNode = nullptr, *prev = nullptr;

    int carry = 0;
    if (head->val >= 5) {
      newNode = new ListNode(carry);
      newNode->next = head;
      prev = newNode;
      curr = newNode->next;
    } else {
      newNode = head;
      curr = newNode;
    }

    while (curr) {
      int d = (curr->val * 2) % 10;
      carry = (curr->val * 2) / 10;
      if (prev) prev->val += carry;
      if (curr) curr->val = d;
      prev = curr;
      curr = curr->next;
    }

    return newNode;
  }
};