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
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode *athNode = list1, *bthNode = list1, *cthNode = list2;
    while (athNode && a > 1) {
      athNode = athNode->next;
      a--;
    }
    while (bthNode && b >= 0) {
      bthNode = bthNode->next;
      b--;
    }
    while (cthNode && cthNode->next) {
      cthNode = cthNode->next;
    }
    athNode->next = list2;
    cthNode->next = bthNode;

    return list1;
  }
};