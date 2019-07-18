/*
  https://leetcode.com/problems/binary-tree-postorder-traversal/

  145. Binary Tree Postorder Traversal

  Given a binary tree, return the postorder traversal of its nodes' values.

  Example:
  Input: [1,null,2,3]
   1
    \
     2
    /
   3

   Output: [3,2,1]
   Follow up: Recursive solution is trivial, could you do it iteratively?
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
  void initVisited( TreeNode *node,unordered_map< TreeNode*, int > &visited ){
    TreeNode *curr;
    stack<TreeNode*> s;
    s.push( node );
    while( !s.empty() ) {
      curr = s.top();
      s.pop();
      visited[ curr ] = 0;
      if( curr->left ) {
	s.push( curr->left );
      }
      if( curr->right ) {
	s.push( curr->right );
      }
    }
  }
    
  vector<int> postorderTraversal( TreeNode* node ) {
    vector<int> inorder;
    // base case 
    if( !node ) {
      return inorder;
    }
    // initialize visited array
    unordered_map< TreeNode*, int > visited;
    initVisited( node, visited );
    visited[ NULL ] = 2;
        
    // mark 2 for visited node
    // mark 1 for node in stack
    TreeNode *curr;
    stack< TreeNode * > s;
    s.push( node );
    visited[node] = 1;
    while( !s.empty() ) {
      curr = s.top();
      s.pop();

      if( visited[ curr->left ] == 2 && visited[ curr->right ] ==2 ) {
	inorder.push_back( curr->val );
	visited[ curr ] = 2;
      }
      if( visited[ curr ] == 1 ) {
	s.push( curr );
	visited[ curr ] = 1;
      }
      if( curr->right && visited[ curr->right ] == 0 ) {
	s.push( curr->right );
	visited[ curr->right ] = 1;
      }
      if( curr->left && visited[ curr->left ] == 0 ) {
	s.push( curr->left );
	visited[ curr->left ] = 1;
      }
    }
    return inorder;
  }
};
