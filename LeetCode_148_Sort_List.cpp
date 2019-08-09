/*
  148. Sort List
  Sort a linked list in O(n log n) time using constant space complexity.

  Example 1:
  Input: 4->2->1->3
  Output: 1->2->3->4

  Example 2:
  Input: -1->5->3->4->0
  Output: -1->0->3->4->5
 */

class Solution {
  ListNode *getMid( ListNode *node ) {
    ListNode *fast = node, *slow = node;
    while( fast && fast->next ) {
      slow = slow->next;
      fast = fast->next->next;
    }
    // set next of node before mid to NULL
    fast = node;
    while( fast->next != slow ) fast = fast->next;
    fast->next = NULL;
    return slow;
  }
    
  ListNode *merge( ListNode *l1, ListNode *l2 ) {
    ListNode *head=NULL, *curr=NULL;
    while( l1 && l2 ) {
      if( l1->val < l2->val ) {
	if( !curr ) {
	  curr = l1;
	  head = curr;
	} else {
	  curr->next = l1;
	  curr = curr->next;
	}
	l1 = l1->next;
      } else {
	if( !curr ) {
	  curr = l2;
	  head = curr;
	} else {
	  curr->next = l2;
	  curr = curr->next;
	}
	l2 = l2->next;
      }
    }
        
    if( l1 ) {
      if( !curr ) {
	curr = l1;
	head = curr;
      } else {
	curr->next = l1;
      }
    }
    if( l2 ) {
      if( !curr ) {
	curr = l2;
	head = curr;
      } else {
	curr->next = l2;
      }
    }
    return head;
  }
    
public:
  ListNode* sortList( ListNode* head ) {
    if( !head || !head->next ) return head;

    ListNode *mid = getMid( head );
    ListNode *left = sortList( head );
    ListNode *right = sortList( mid );
    return merge( left, right );
  }
};
