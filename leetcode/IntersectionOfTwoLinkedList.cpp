#include<algorithm>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
 public:
  int length(ListNode *head) {
    int length = 0;
    while (head != nullptr) {
      ++length;
      head = head->next;
    }
    return length;
  }
  ListNode *move(ListNode *head, int len) {
    while (len--) {
      head = head->next;
    }
    return head;
  }
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lengthA = length(headA);
    int lengthB = length(headB);
    int diff = abs(lengthA - lengthB);
    if (lengthA > lengthB) {
      headA = move(headA, diff);
    } else {
      headB = move(headB, diff);
    }
    while (headA != nullptr and headB != nullptr and headA != headB) {
      headA = headA->next;
      headB = headB->next;
    }
    return (headA == nullptr ? headA : headB);
  }
};