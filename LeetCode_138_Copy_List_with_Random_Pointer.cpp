/*
  https://leetcode.com/problems/copy-list-with-random-pointer/

  138. Copy List with Random Pointe
  
  A linked list is given such that each node contains an additional random pointer
  which could point to any node in the list or null.

  Return a deep copy of the list.
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
  Node* copyRandomList(Node* head) {
    if( head == NULL ) {
      return NULL;
    }
        
    Node *newHead = NULL;
    Node *curr = head;
    unordered_map< Node*, Node* > oldToNew;
    while( curr ) {
      newHead = new Node( curr->val, NULL, NULL );
      oldToNew[ curr ] = newHead;
      curr = curr->next;
    }
        
    // map next and random pointer
    curr = head;
    while( curr ) {
      oldToNew[ curr ]->next = oldToNew[ curr->next ];
      oldToNew[ curr ]->random = oldToNew[ curr->random ];
      curr = curr->next;
    }
    return oldToNew[ head ];
  }
};

