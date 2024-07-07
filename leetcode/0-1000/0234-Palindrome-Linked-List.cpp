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

  bool checkPalindrome(ListNode* head, ListNode* reverse) {
    while (reverse) {
      if (head->val != reverse->val) return false;
      head = head->next;
      reverse = reverse->next;
    }
    return true;
  }

 public:
  bool isPalindrome(ListNode* head) {
    ListNode* mid = midOfList(head);
    ListNode* reverse = reverseList(mid);

    return checkPalindrome(head, reverse);
  }
};