/*
  116. Populating Next Right Pointers in Each Node
   You are given a perfect binary tree where all leaves are on the same level,
   and every parent has two children. The binary tree has the following definition:

   struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
  }
  Populate each next pointer to point to its next right node. If there is no next right node,
  the next pointer should be set to NULL.
  Initially, all next pointers are set to NULL.
*/

/* We traverse the tree level by level using the next pointer set at the parent level.
   While doing so we set the next pointers at child level. */

class Solution {
public:
  Node* connect( Node* root ) {
    if( !root ) return NULL;
        
    Node *parent = root;
    Node *firstNode = root->left; // points to first node of a level
    while( firstNode ) {
      Node *curr = firstNode; // curr pointer traverses tree level by level
      while( curr ) {
	curr->next = parent->right;
	curr = curr->next;
	parent = parent->next;
	curr->next = parent ? parent->left : NULL;
	curr = curr->next;
      }
      parent = firstNode;
      firstNode = firstNode->left;
    }
    return root;
  }
};
