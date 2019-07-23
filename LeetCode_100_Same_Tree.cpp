/*
  https://leetcode.com/problems/same-tree/

  100. Same Tree
  Given two binary trees, write a function to check if they are the same or not.
  Two binary trees are considered the same if they are structurally identical
  and the nodes have the same value.
 */

class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if( p == NULL && q != NULL ) return false;
    if( q == NULL && p != NULL ) return false;
    if( p == NULL && q == NULL ) return true;
    if( p->val != q->val ) return false;
    return isSameTree( p->left, q->left ) && isSameTree( p->right, q->right );
  }
};
