/*
  107. Binary Tree Level Order Traversal II

  Given a binary tree, return the bottom-up level order traversal
  of its nodes' values. (ie, from left to right, level by level
  from leaf to root).

  For example:
  Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
   return its bottom-up level order traversal as:
   [
   [15,7],
   [9,20],
   [3]
   ]
*/

class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    if( !root ) return result;
        
    vector<int> tmp; // to store the values at one level
    tmp.push_back( root->val );

    vector<TreeNode*> parent, children;
    parent.push_back( root );
    while( parent.size() > 0 ) {
      result.push_back( tmp ); tmp.clear();   
      for( auto node : parent ) {
	if( node->left ) {
	  children.push_back( node->left );
	  tmp.push_back( node->left->val );    
	}
	if( node->right ) {
	  children.push_back( node->right );
	  tmp.push_back( node->right->val );
	}
      }
      parent = children;
      children.clear();
    }
    reverse( result.begin(), result.end() );
    return result;
  }
};
