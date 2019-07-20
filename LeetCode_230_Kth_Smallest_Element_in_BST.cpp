/*
  https://leetcode.com/problems/kth-smallest-element-in-a-bst/

  230. Kth Smallest Element in a BST

  Given a binary search tree, write a function kthSmallest to find the kth
  smallest element in it.

  Note: 
  You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

  Example 1:
  Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
   Output: 1

   Example 2:
   Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
 Output: 3
*/

// Approach 1 Using recursive inorder traversal
class Solution {
public:
  void getInorder( TreeNode *root, vector<int> &inorder ) {
    if( !root ) return;
    if( root->left ) getInorder( root->left, inorder );
    inorder.push_back( root->val );
    if( root->right ) getInorder( root->right, inorder );
  }
    
  int kthSmallest( TreeNode* root, int k ) {
    vector<int> inorder;
    getInorder( root, inorder );
    return inorder[k-1];
  }
};
