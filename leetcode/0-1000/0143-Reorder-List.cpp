struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
  ListNode* midOfList(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  ListNode* reverseList(ListNode* temp) {
    ListNode *curr = temp, *prev, *nxt;
    prev = nxt = nullptr;
    while (curr) {
      nxt = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nxt;
    }
    return prev;
  }

  void merge(ListNode* head, ListNode* reverse) {
    ListNode *headNext, *reverseNext;
    while (reverse) {
      headNext = head->next;
      head->next = reverse;
      reverseNext = reverse->next;
      reverse->next = headNext;
      head = headNext;
      reverse = reverseNext;
    }
  }

 public:
  void reorderList(ListNode* head) {
    ListNode* mid = midOfList(head);
    ListNode* reverse = reverseList(mid->next);
    mid->next = nullptr;

    merge(head, reverse);
  }
};