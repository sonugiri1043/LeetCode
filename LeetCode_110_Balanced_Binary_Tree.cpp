/*
  110. Balanced Binary Tree

  Given a binary tree, determine if it is height-balanced.
  For this problem, a height-balanced binary tree is defined as:

  a binary tree in which the depth of the two subtrees of every node
  never differ by more than 1.

  Example 1:
  Given the following tree [3,9,20,null,null,15,7]:
    3
   / \
  9  20
    /  \
   15   7
   Return true.

   Example 2:
   Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
 Return false.
*/

// O( N logN )
class Solution {
  int getHeight( TreeNode *node ) {
    if( !node ) return 0;
    return max( getHeight( node->left ), getHeight( node->right ) ) + 1;
  }
    
public:
  bool isBalanced( TreeNode *node ) {
    if( !node ) return true;
    if( abs( getHeight( node->left ) - getHeight( node->right ) ) > 1 )
      return false;
    if( !isBalanced( node->left ) || !isBalanced( node->right ) ) {
      return false;
    }
    return true;
  }
};

// O( N )
class Solution {
  map<TreeNode*, int> height;
    
  int getHeight( TreeNode *node ) {
    if( !node ) return 0;
    if( height.count(node) ) return height[node];
        
    if( !height.count(node->left) ) height[node->left] = getHeight(node->left);
    if( !height.count(node->right) ) height[node->right] = getHeight(node->right);

    return max( height[ node->left ], height[ node->right ] ) + 1;
  }
    
public:
  bool isBalanced( TreeNode *node ) {
    if( !node ) return true;
    if( abs( getHeight( node->left ) - getHeight( node->right ) ) > 1 )
      return false;
    if( !isBalanced( node->left ) || !isBalanced( node->right ) ) {
      return false;
    }
    return true;
  }
};
