/*
  Vertical Order Traversal of a Binary Tree [Leetcode 987]

  Given a binary tree, return the vertical order traversal of its nodes values.
  For each node at position (X, Y), its left and right children respectively will
  be at positions (X-1, Y-1) and (X+1, Y-1).
  https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

  Return a list of non-empty reports in order of X coordinate.  Every report will
  have a list of values of nodes.
 */

class Solution {
  map< int, map<int, multiset<int> > > levels;
public:
  void helper( TreeNode *node, int x, int y ) {
    if( !node ) return;
    levels[x][y].insert( node->val );    
    helper( node->left, x-1, y+1 );
    helper( node->right, x+1, y+1 );
  }
    
  vector<vector<int>> verticalTraversal( TreeNode* root ) {
    helper( root, 0, 0 );
        
    vector<vector<int>> result;        
    for( auto x : levels ) {
      result.push_back( {} );
      for( auto y : x.second )
	for( auto val : y.second )
	  result[ result.size() - 1 ].push_back( val );
    }
    return result;
  }
};
