/*
  143. Reorder List
  Given a singly linked list L: L0→L1→…→Ln-1→Ln,
  reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

  You may not modify the values in the list's nodes, only nodes itself may be changed.
  
  Example 1:
  Given 1->2->3->4, reorder it to 1->4->2->3.
  Example 2:
  Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
  ListNode* reverse( ListNode *head ) {
    if( head == nullptr ) return head;
    ListNode *prev=nullptr, *curr=head, *next;
    while( curr ) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
    
  ListNode* middle( ListNode *head ) {
    ListNode *fast=head->next, *slow=head;
    while( fast && fast->next ) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;

  }

  void insert( ListNode *h1, ListNode *h2 ) {
    ListNode *curr1=h1, *next1, *curr2=h2, *next2;
    while( curr1 && curr2 ) {
      next1 = curr1->next;
      next2 = curr2->next;
      curr1->next = curr2;
      curr2->next = next1;
      curr1 = next1;
      curr2 = next2;
    }
        
  }
public:
  void reorderList( ListNode* head ) {
    if( !head || !( head->next ) ) return;
    
    // get the middle
    ListNode *prevToMid = middle( head );
    // reverse the second half
    ListNode *mid = reverse( prevToMid->next );
    prevToMid->next = nullptr;
    // merge
    insert( head, mid );
  }
};
