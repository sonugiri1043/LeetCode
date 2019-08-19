/*
  111. Minimum Depth of Binary Tree

  Given a binary tree, find its minimum depth.
  The minimum depth is the number of nodes along the shortest path
  from the root node down to the nearest leaf node.

  Note: A leaf is a node with no children.
  Example:
  Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
   return its minimum depth = 2
 */

class Solution {
    
public:
  int minDepth( TreeNode* root ) {
    if( !root ) return 0;
        
    int level=0;
    vector<TreeNode*> parent, child;
    parent.push_back( root );
    while( !parent.empty() ) {
      ++level;
      for( auto curr : parent ) {
	if( !curr->left && !curr->right ) return level;
	if( curr->left ) child.push_back( curr->left );
	if( curr->right ) child.push_back( curr->right );
      }
      parent = child;
      child.clear();
    }
    return level;
  }
};
