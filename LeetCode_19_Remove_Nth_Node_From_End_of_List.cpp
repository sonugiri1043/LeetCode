/*
  https://leetcode.com/problems/remove-nth-node-from-end-of-list/

  19. Remove Nth Node From End of List

  Given a linked list, remove the n-th node from the end of list and return its head.
  Example:
  Given linked list: 1->2->3->4->5, and n = 2.
  After removing the second node from the end, the linked list becomes 1->2->3->5.

  Note:
  Given n will always be valid.

  Follow up:
  Could you do this in one pass?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    // first ptr woulds always point to one node before
    // the deleted node
    ListNode *first = NULL;
    ListNode *second = head;
    while( n && second ) {
      // advance second n times
      n--;
      second = second->next;
    }
    cout << second->val << endl;
    while( second ) {
      if( !first )  { 
	first = head;
      } else {
	first = first->next;
      }
      second = second->next;
    }
        
    // Delete node
    ListNode *tmp = NULL;
    if( NULL == first ){
      // when head has to be deleted
      tmp = head->next;
      delete head;
      return tmp;
    }
    // any node other than head
    tmp = first->next;
    if( first->next )
      first->next = first->next->next;
    delete tmp;
    return head;
  }
};
