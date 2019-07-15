/*
  https://leetcode.com/problems/merge-two-sorted-lists/
  
  21. Merge Two Sorted Lists
  
  Merge two sorted linked lists and return it as a new list. The new list should be made
  by splicing together the nodes of the first two lists.

  Example:
  Input: 1->2->4, 1->3->4
  Output: 1->1->2->3->4->4
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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *newHead = NULL;
    ListNode *curr = NULL;
    ListNode *tmp = NULL;
        
    while( l1 && l2 ) {
      if( l1->val <= l2->val ) {
	tmp = l1;
	l1 = l1->next;
      } else {
	tmp = l2;
	l2 = l2->next;
      }
      if( !curr ) { 
	curr = tmp;
	newHead = curr;
      } else {
	curr->next = tmp;
	curr = curr->next;
      }
    } 
    if( l1 ) tmp = l1;
    if( l2 ) tmp = l2;
    if( tmp ) {
      if( curr ) {
	curr->next = tmp;
      } else {
	curr = tmp;
      }
    }
    return newHead ? newHead : curr;
  }
};
