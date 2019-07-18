/*
  94. Binary Tree Inorder Traversal

  Given a binary tree, return the inorder traversal of its nodes' values.

  Example:
  Input: [1,null,2,3]
   1
    \
     2
    /
   3

   Output: [1,3,2]
   Follow up: Recursive solution is trivial, could you do it iteratively?
 */

class Solution {
public:
    
  vector<int> inorderTraversal( TreeNode* node ) {
    vector<int> inorderPath;       
    TreeNode *curr=node;   
    stack<TreeNode*> st;
    while(1) {
      while( curr ) {
	st.push( curr );
	curr = curr->left;
      }
            
      if( st.empty() ) break;
            
      curr = st.top();
      st.pop();
      inorderPath.push_back( curr->val );
            
      // point curr to right sub-tree
      curr = curr->right;
    }
    return inorderPath;
  }
};


// another approach
class Solution {
public:
  void initVisited( TreeNode *node,unordered_map< TreeNode*, int > &visited ) {
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
    
  vector<int> inorderTraversal( TreeNode* node ) {
    vector<int> inorder;
    if( !node ) {
      return inorder;
    }
    unordered_map< TreeNode*, int > visited;
    initVisited( node, visited );
    visited[ NULL ] = 2;
        
    TreeNode *curr;
    stack< TreeNode * > s;
    s.push( node );
    visited[node] = 1;
    while( !s.empty() ) {
      curr = s.top();
      s.pop();
            
      if( visited[ curr->left ] == 2 ) {
	inorder.push_back( curr->val );
	visited[ curr ] = 2;
      }
            
      if( curr->right && visited[ curr->right ] == 0 ) {
	s.push( curr->right );
	visited[ curr->right ] = 1;
      }
      if( visited[ curr ] == 1 ) {
	s.push( curr );
	visited[ curr ] = 1;
      }
      if( curr->left && visited[ curr->left ] == 0 ) {
	s.push( curr->left );
	visited[ curr->left ] = 1;
      }
    }
    return inorder;
  }
};
