/*
  https://leetcode.com/problems/reverse-linked-list/

  206. Reverse Linked List
  Reverse a singly linked list.

  Example:
  
  Input: 1->2->3->4->5->NULL
  Output: 5->4->3->2->1->NULL
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
  ListNode* reverseList(ListNode* head) {
    ListNode *curr = head;
    ListNode *prev = NULL;
    ListNode *next = NULL;
    while( curr ) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return curr ? curr : prev;
  }
};
