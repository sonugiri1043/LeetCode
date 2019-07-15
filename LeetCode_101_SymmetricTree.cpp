/*
  Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

  For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
  
    1
   / \
  2   2
 / \ / \
3  4 4  3
 
But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  bool isSymmetricUtil( TreeNode *left, TreeNode *right ) {
    if( left == NULL && right == NULL )  {
      return true;
    }
    if( left == NULL || right == NULL ) {
      return false;
    }
    if( left->val != right->val ) {
      return false;
    }
    return ( isSymmetricUtil( left->left, right->right ) && 
	     isSymmetricUtil( left->right, right->left ) );
  }
    
  bool isSymmetric(TreeNode* root) {
    if( !root ) {
      return true;
    }
    return isSymmetricUtil( root->left, root->right );
  }
};
