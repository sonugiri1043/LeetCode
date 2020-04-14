/*
  61. Rotate List

  Given a linked list, rotate the list to the right by k places, where k is non-negative.

  Example 1:
  Input: 1->2->3->4->5->NULL, k = 2
  Output: 4->5->1->2->3->NULL

  Example 2:
  Input: 0->1->2->NULL, k = 4
  Output: 2->0->1->NUL
 */

class Solution {
public:
  ListNode* rotateRight( ListNode* head, int k ) {
    if( !head || !head->next ) return head;
        
    // Get the length of linked list 
    int lenOfLL = 1;
    ListNode *curr = head;
    while( curr->next ) {
      ++lenOfLL;
      curr=curr->next;
    }
    k = k % lenOfLL; // incase k > length of link list
    if( k == 0 ) return head; // no need to rotate
        
    // Connect tail to head and detach linked-list at position "lenOfLL - k"
    // to rotate right by k
    curr->next = head;
    ListNode *ptr=head;
    int count = lenOfLL - k;
    while( --count ) {
      ptr = ptr->next;
    }
    ListNode *newHead = ptr->next;
    ptr->next = nullptr; // detach link list 
        
    return newHead;
  }
};
