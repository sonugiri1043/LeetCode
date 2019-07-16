/*
  234. Palindrome Linked List

  Given a singly linked list, determine if it is a palindrome.

  Example 1:
  
  Input: 1->2
  Output: false
  Example 2:
  
  Input: 1->2->2->1
  Output: true
  Follow up:
  Could you do it in O(n) time and O(1) space?
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
  ListNode* reverse( ListNode* node ) {
    // reverses link list
    ListNode *curr = node, *prev = NULL, *next = NULL;
    while( curr ) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return curr ? curr : prev;
  } 
    
  bool isPalindrome(ListNode* node ) {
    if( !node || !node->next) {
      // base case
      return true;
    }
        
    // get length of linked list
    int len = 0;
    ListNode *curr = node;
    while( curr ) {
      len++;
      curr = curr->next;
    }
        
    // move the curr pointer to middle of linked list
    int mid = (len-1)/2;
    curr = node;
    while( mid ) {
      curr = curr->next;
      mid--;
    }
        
    // Reverse the 2nd half of linked list
    ListNode *rev = reverse( curr->next );
        
    // compare orig linked list and reveresed link list till mid
    curr = node;
    mid = len/2;
    while( mid && rev) {
      mid--;
      if( rev->val != curr->val ) {
	return false;
      }
      rev = rev->next;
      curr = curr->next;
    }
    return true;     
  }
};


class Solution {
public:
  bool printRecursive( ListNode* node, queue<int> &q ) {
    if( !node )
      return true;

    q.push( node->val );
    bool ret = printRecursive( node->next, q );
    int val = q.front();
    q.pop();
    return ret && ( val == node->val );
  } 
    
  bool isPalindrome(ListNode* node ) {
    queue<int> q;
    return printRecursive( node, q );
  }
};
