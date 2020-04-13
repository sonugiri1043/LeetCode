/*
  92. Reverse Linked List II
  
  Reverse a linked list from position m to n. Do it in one-pass.
  Note: 1 ≤ m ≤ n ≤ length of list.

  Example:
  Input: 1->2->3->4->5->NULL, m = 2, n = 4
  Output: 1->4->3->2->5->NUL
 */

class Solution {
public:
  ListNode* reverseBetween( ListNode* head, int m, int n ) {
    // use dummy node to handle m=1 case
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
        
    // obtain node before m and node after n and reverse the linked list b/w m and n
    ListNode *nextToN = head;
    while( n ) {
      nextToN = nextToN->next;
      --n;
    }
    ListNode *preToM = dummyHead;
    while( m > 1 ) {
      preToM = preToM->next;
      --m;
    }
        
    // reverse linked-list b/w m and n
    ListNode *prev = nextToN, *curr = preToM->next, *next;
    while( curr != nextToN ) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    preToM->next = prev;
    return dummyHead->next;
  }
};
