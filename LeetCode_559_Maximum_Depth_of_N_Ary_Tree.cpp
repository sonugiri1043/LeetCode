/*
  559. Maximum Depth of N-ary Tree
  Given a n-ary tree, find its maximum depth.

  The maximum depth is the number of nodes along the longest path from
  the root node down to the farthest leaf node.
 */

class Solution {
public:
  int maxDepth( Node* root ) {
    if( !root ) return 0;
    int maxHeight = 0;
    for( auto node : root->children ) {
      maxHeight = max( maxHeight, maxDepth( node ) );
    }
    return 1 + maxHeight;
  }
};
