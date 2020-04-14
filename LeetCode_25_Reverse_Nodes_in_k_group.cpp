/*
  25. Reverse Nodes in k-Group
  
  Given a linked list, reverse the nodes of a linked list k at a time
  and return its modified list.

  k is a positive integer and is less than or equal to the length of the
  linked list. If the number of nodes is not a multiple of k then left-out
  nodes in the end should remain as it is.

  Example:
  Given this linked list: 1->2->3->4->5
  For k = 2, you should return: 2->1->4->3->5
  For k = 3, you should return: 3->2->1->4->5
 */

class Solution {
public:
  ListNode* reverseKGroup( ListNode* head, int k ) {  
    // if no of nodes is less than k then don't reverse
    int n = 0;
    ListNode *node = head;
    while( n < k && node ) {
      node=node->next;
      n++;
    }
    if( n < k )  return head;
        
        
    ListNode *prev=nullptr, *curr = head, *next = nullptr;
    int count = 0;
    /* reverse first k nodes of the linked list */
    while( curr != NULL && count < k ) {  
      next = curr->next;  
      curr->next = prev;  
      prev = curr;  
      curr = next;  
      count++;  
    }
      
    /* curr is now a pointer to ( k+1 )th node  
        Recursively call for the list starting from current.  
        And make rest of the list as next of first node */
    head->next = reverseKGroup( curr, k );  
  
    /* prev is new head of the input list */
    return prev;
  }
};
