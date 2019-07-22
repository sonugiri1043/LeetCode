/*
  https://leetcode.com/problems/validate-binary-search-tree/

  98. Validate Binary Search Tree
  Given a binary tree, determine if it is a valid binary search tree (BST).

  Assume a BST is defined as follows:
  The left subtree of a node contains only nodes with keys less than the node's key.
  The right subtree of a node contains only nodes with keys greater than the node's key.
  Both the left and right subtrees must also be binary search trees.
 
Example 1:
    2
   / \
  1   3

Input: [2,1,3]
Output: true

Example 2:
    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4. */

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
  int getMax( TreeNode *node ) {
    if( node->right ) {
      return getMax( node->right );
    }
    return node->val;
  }
    
  int getMin( TreeNode *node ) {
    if( node->left ) {
      return getMin( node->left );
    }
    return node->val;
  }
    
public:
  bool isValidBST(TreeNode* root) {
    if( !root ) return true;
    int maxLeft, minRight;
    if( root->left ) {
      maxLeft = getMax( root->left );
      if( root->val <= maxLeft ) return false;
    }
    if( root->right ) {
      minRight = getMin( root->right );
      if( root->val >= minRight ) return false;
    }
    return isValidBST( root->left ) && isValidBST( root->right );
  }
};
