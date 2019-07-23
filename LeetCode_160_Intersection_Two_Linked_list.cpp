/*
  160. Intersection of Two Linked List
  Write a program to find the node at which the intersection of two singly linked lists begins.
 */

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_map< ListNode *, bool > listA;
    while( headA ) {
      listA[headA] = true;
      headA = headA->next;
    }
    while( headB ) {
      if( listA.find( headB ) != listA.end() )
	return headB;
      headB = headB->next;
    }
    return NULL;
  }
};
