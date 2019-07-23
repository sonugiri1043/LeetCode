/*
  236. Lowest Common Ancestor of a Binary Tree

  Given a binary tree, find the lowest common ancestor (LCA)
  of two given nodes in the tree.

  According to the definition of LCA on Wikipedia: “The lowest common ancestor
  is defined between two nodes p and q as the lowest node in T that has both p
  and q as descendants (where we allow a node to be a descendant of itself).”
*/

/**
    Alternate solution is to store traverse p and q and store their parent pointer.
    check for last common point.
*/
class Solution {
public:
  bool present( TreeNode *root, TreeNode *node ) {
    if( !root ) return false;
    if( node == root ) return true;
    return present( root->left, node ) || present( root->right, node );
  }
    
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if( p == root && q == root ) return root;
    if( root->left && present( root->left, p ) &&
	present( root->left, q ) ) {
      return lowestCommonAncestor( root->left, p, q );
    } else if( root->right && present( root->right, p ) &&
	       present( root->right, q ) ) {
      return lowestCommonAncestor( root->right, p, q );
    }
    return root;
  }
};
