/*
  654. Maximum Binary Tree

  Given an integer array with no duplicates. A maximum tree building on this
  array is defined as follow:

  1. The root is the maximum number in the array.
  2. The left subtree is the maximum tree constructed from left part subarray
  divided by the maximum number.
  3. The right subtree is the maximum tree constructed from right part subarray
  divided by the maximum number.
  
  Construct the maximum tree by the given array and output the root node of
  this tree.

  Example 1:
  Input: [3,2,1,6,0,5]
  Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
 */

class Solution {
  TreeNode* maximumTree( vector<int> &nums, int start, int end ) {
    if( start > end || start < 0 || end > nums.size() - 1) return NULL;
    if( start == end ) return new TreeNode( nums[start] );
    int max = INT_MIN;
    int index = -1;
    for( int i=start; i <= end; i++ ) {
      if( nums[i] > max ) {
	max = nums[i];
	index = i;
      }
    }
    TreeNode *node = new TreeNode( max );
    node->left = maximumTree( nums, start, index - 1 );
    node->right = maximumTree( nums, index + 1, end );
    return node;
        
  }
public:
  TreeNode* constructMaximumBinaryTree( vector<int>& nums ) {
    return maximumTree( nums, 0, nums.size() - 1 );
  }
};
