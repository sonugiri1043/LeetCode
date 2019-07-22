/*
  https://leetcode.com/problems/binary-tree-level-order-traversal/

  102. Binary Tree Level Order Traversal
  Given a binary tree, return the level order traversal of its nodes' values.
  (ie, from left to right, level by level).

  For example:
  Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
   return its level order traversal as:
   [
   [3],
   [9,20],
   [15,7]
   ]*/

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> levels;
    if( !root ) return levels;
        
    vector<int> level;
    vector<TreeNode*> parents;
    vector<TreeNode*> children;
    parents.push_back( root );
    while( parents.size() > 0 ) {
      for( auto parent : parents ) {
	if( parent->left ) children.push_back( parent->left );
	if( parent->right ) children.push_back( parent->right );
	level.push_back( parent->val );
      }
      levels.push_back( level );
      level.clear();
      parents = children;
      children.clear();
    }
    return levels;
  }
};
