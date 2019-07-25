/*
  105. Construct Binary Tree from Preorder and Inorder Traversal

  Given preorder and inorder traversal of a tree, construct the binary tree.

  Note:
  You may assume that duplicates do not exist in the tree.
  For example, given

  preorder = [3,9,20,15,7]
  inorder = [9,3,15,20,7]
  Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

*/

class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder ) {
    size_t size = preorder.size();
    return buildTree( preorder, 0, size - 1, inorder, 0, size - 1 );
  }
    
  TreeNode* buildTree( vector<int>& preorder, int pstart, int pend,
		       vector<int>& inorder, int istart, int iend ) {
    if( pend < pstart || iend < istart ) return NULL;

    // first node in pre-order is the root
    TreeNode *node = new TreeNode( preorder[pstart] );
    // search for root in in-order to know the size of left and right sub-tree
    int index = istart;
    while( inorder[index] != preorder[pstart] ) 
      index++;
        
    node->left = buildTree( preorder, pstart + 1, pstart + ( index - istart ),
			    inorder, istart, index - 1 );
    node->right = buildTree( preorder, pstart + 1 + ( index - istart ), pend,
			     inorder,  index + 1 , iend );
    return node;
  }
};
