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

// Iterative
class Solution {    
public:
  vector<int> preorder( Node* root ) {
    vector<int> result;
    if( !root ) return result;
        
    stack<Node*> s;
    s.push( root );
    Node *curr;
    while( !s.empty() ) {
      curr = s.top(); s.pop();
      result.push_back( curr->val );            
      for( auto it=curr->children.rbegin(); it!=curr->children.rend(); ++it )
	s.push( *it );
    }
    return result;
  }
}
