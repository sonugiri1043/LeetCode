/*
  https://leetcode.com/problems/n-ary-tree-postorder-traversal/

  590. N-ary Tree Postorder Traversal

  Given an n-ary tree, return the postorder traversal of its nodes' values.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
  void getPostOrder( Node *node, vector<int> & arr ) {
    if( !node ) {
      return;
    }
    for( auto it = node->children.begin(); it != node->children.end(); it++ ) {
      getPostOrder( *it, arr );
    }
    arr.push_back( node->val );
  }
    
  vector<int> postorder(Node* root) {
    vector<int> arr;
    getPostOrder( root, arr );
    return arr;
  }
};
