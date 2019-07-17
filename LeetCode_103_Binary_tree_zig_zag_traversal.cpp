/*
  https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

  103. Binary Tree Zigzag Level Order Traversal
  
  Given a binary tree, return the zigzag level order traversal of its node's values.
  (ie, from left to right, then right to left for the next level and alternate between).

  For example:
  Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> levels;
    // Base case
    if( !root ) return levels;
        
    vector<int> level;
    int levelNo = 0;
        
    // Do a level order traversal and push nodes at each level in levels
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    q1.push(root);
    level.push_back( root->val );
    TreeNode *curr = NULL;
    while( !q1.empty() ) {
      if( levelNo % 2 == 1 ) {
	// reverse the direction at alternate levels
	reverse( level.begin(), level.end() );
      }
      levels.push_back( level );
      level.clear();
            
      while( !q1.empty() ) {
	curr = q1.front();
	q1.pop();
	if( curr->left ){
	  q2.push( curr->left );
	  level.push_back( curr->left->val );
	}
	if( curr->right ) {
	  q2.push( curr->right );
	  level.push_back( curr->right->val );
	}
      }
            
      q1 = q2;
      //clear q2
      while( !q2.empty() ) q2.pop();
            
      levelNo++;
    }
    return levels;
  }
};
