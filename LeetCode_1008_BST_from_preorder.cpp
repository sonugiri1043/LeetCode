/*
  1008. Construct Binary Search Tree from Preorder Traversal

  Return the root node of a binary search tree that matches the given preorder traversal.
 */

class Solution {
public:
  TreeNode* bst( vector<int> &preorder, int start, int end ) {
    TreeNode *node=nullptr;
    if( end < start ) return node;
    if( start == end ) return new TreeNode( preorder[ start ] );
        
    node = new TreeNode(  preorder[start] );

    int j = start;
    while( j <= end && preorder[start] >= preorder[j] )  j++;

    node->left = bst( preorder, start + 1, j - 1 );
    node->right = bst( preorder, j, end );
    return node;
  }
    
  TreeNode* bstFromPreorder( vector<int>& preorder ) { 
    return bst( preorder, 0, preorder.size() - 1 );
  }
};
