/*
  124. Binary Tree Maximum Path Sum
  Given a non-empty binary tree, find the maximum path sum.

  For this problem, a path is defined as any sequence of nodes from some
  starting node to any node in the tree along the parent-child connections.
  The path must contain at least one node and does not need to go through the root.

  Example 1:
  Input: [1,2,3]
       1
      / \
     2   3
Output: 6

Example 2:
Input: [-10,9,20,null,null,15,7]
   -10
   / \
  9  20
    /  \
   15   7
Output: 42
*/

/*
  This problem maximum has 4 situation:
  1. pick root
  2. pick left branch
  3. pick right branch
  4. pick branch go through root with positive left branch and right branch.
 */

int helper( TreeNode *node, int &maxSum ) {
  maxSum = max( maxSum, node->val );
        
  // leaf node
  if( !node->left && !node->right ) return node->val;
             
  int left = 0, right = 0, maxPath;
  // both left and right node are present
  if( node->left && node->right ) {
    left = helper( node->left, maxSum );
    right = helper( node->right, maxSum );
            
    maxPath = max( left + node->val, right + node->val );
    maxSum = max( maxPath, maxSum );
    maxSum = max( left + right + node->val, maxSum );
    return max( maxPath, node->val );
  } else if( node->right ) {
    right = helper( node->right, maxSum );
    maxSum = max( right + node->val, maxSum );
    return max( node->val, node->val + right );
  } else {
    left = helper( node->left, maxSum );
    maxSum = max( left + node->val, maxSum );
    return max( node->val, node->val + left );
  }
}
    
int maxPathSum( TreeNode* root ) {
  int maxSum = INT_MIN;
  helper( root, maxSum );
  return maxSum;
}
};
