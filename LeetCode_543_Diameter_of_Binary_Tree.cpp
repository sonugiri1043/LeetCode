/*
  543. Diameter of Binary Tree
  Given a binary tree, you need to compute the length of the diameter
  of the tree. The diameter of a binary tree is the length of the longest
  path between any two nodes in a tree. This path may or may not pass
  through the root.

  Example:
  Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    

  Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

  Note: The length of path between two nodes is represented by the number
  of edges between them.
*/

/*
  You can use memoisation to reduce the time complexity.
  The diameter need not pass through the root, that's why we check all the
  nodes in diameterOfBinaryTree function and return the one with max.
 */
class Solution {
  int getMaxDepth( TreeNode *node ) {
    if( !node ) return 0;
    int left = getMaxDepth( node->left );
    int right = getMaxDepth( node->right );
    return 1 + max( left, right ); 
  }
    
public:
  int diameterOfBinaryTree( TreeNode* node ) {
    if( !node ) return 0;
    int d = getMaxDepth( node->left ) + getMaxDepth( node->right );
    return max( max( d, diameterOfBinaryTree( node->left ) ),
		max( d, diameterOfBinaryTree( node->right ) ) );
  }
};
