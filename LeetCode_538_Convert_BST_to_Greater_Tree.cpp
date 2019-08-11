/*
  538. Convert BST to Greater Tree
  Given a Binary Search Tree (BST), convert it to a Greater Tree such that
  every key of the original BST is changed to the original key plus sum of
  all keys greater than the original key in BST.

  Example:
  Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

  Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
 */

class Solution {
  int getGreaterTree( TreeNode *node, int sum ) {
    if( !node ) return sum;
    int rightsum = getGreaterTree( node->right, sum );
    node->val += rightsum;
    int leftsum = getGreaterTree( node->left, node->val );
    return leftsum;
  }
public:
  TreeNode* convertBST( TreeNode* root ) {
    getGreaterTree( root, 0 );
    return root;
  }
};
