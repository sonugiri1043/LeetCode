/*
  83. Remove Duplicates from Sorted List
  Given a sorted linked list, delete all duplicates such that each
  element appear only once.

  Example 1:
  Input: 1->1->2
  Output: 1->2

  Example 2:
  Input: 1->1->2->3->3
  Output: 1->2->3
 */

class Solution {
public:
  ListNode* deleteDuplicates( ListNode* head ) {
    ListNode *curr = head, *tmp;
    while( curr && curr->next ) {
      if( curr->val == curr->next->val ) {
	tmp = curr->next;
	curr->next = curr->next->next;
	delete tmp;
      } else {
	curr = curr->next;
      }
    }
    return head;
  }
};
