/*
  https://leetcode.com/problems/remove-linked-list-elements/

  203. Remove Linked List Elements
  Remove all elements from a linked list of integers that have value val.

  Example:
  Input:  1->2->6->3->4->5->6, val = 6
  Output: 1->2->3->4->5
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
  ListNode* removeElements(ListNode* head, int val) {
    // introduce dummy node to handle edge cases
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
        
    ListNode *newHead = dummy;
    ListNode *tmp;
    while( dummy->next ) {
      if( dummy->next->val == val ) {
	// remove this node
	tmp = dummy->next;
	dummy->next = dummy->next->next;
	delete tmp;
      } else if( dummy->next ) {
	dummy = dummy->next;
      }
    }
    return newHead->next;
  }
};
