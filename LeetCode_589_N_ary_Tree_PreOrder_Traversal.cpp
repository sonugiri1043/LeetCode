/*
  589. N-ary Tree Preorder Traversal
  Given an n-ary tree, return the preorder traversal of its nodes' values.
 */

class Solution {
  void preOrder( Node* node, vector<int> &result ) {
    if( !node ) return;
    result.push_back( node->val );
    for( auto n : node->children )
      preOrder( n, result );
  }
    
public:
  vector<int> preorder( Node* root ) {
    vector<int> result;
    preOrder( root, result );
    return result;
  }
};
