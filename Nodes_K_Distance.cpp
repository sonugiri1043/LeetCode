// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
/*
  We are given a binary tree (with root node root), a target node, and an integer value K.
  Return a list of the values of all nodes that have a distance K from the target node.
  The answer can be returned in any order.
*/

#include <iostream>
#include <queue>
#include <unordered_map>

using std::cout;
using std::endl;
using std::queue;
using std::unordered_map;

struct Node {
  int data;
  Node *left, *right;
  Node( int data_ ) : data( data_ ), left( NULL ), right( NULL ) {}
};

void getChildParentMap( Node *node,
			unordered_map<Node*, Node*> &childParentMap ) {
  if( node ) {
    if( node->left )
      childParentMap[ node->left ] = node;
    if( node->right )
      childParentMap[ node->right ] = node;
  }
}

queue< Node* > getNodesKDistanceAway( Node *root, Node *target, int k ) {
  unordered_map<Node*, Node*> childParentMap;
  childParentMap[ root ] = nullptr;
  getChildParentMap( root, childParentMap );

  queue< Node* > levelQ;
  queue< Node* > levelQChild;
  unordered_map<Node*, bool> visited;
  levelQ.push( target );
  visited[ nullptr ] = true;
  visited[ target ] = true;

  int level = 0;
  Node *node;
  while( level != 2 && !levelQ.empty() ) {
    while( !levelQ.empty() ) {
      node = levelQ.front();
      levelQ.pop();
      if( node->left && visited.find( node->left ) == visited.end() ) {
	levelQChild.push( node->left );
	visited[ node->left ] = true;
      }
      if( node->right && visited.find( node->right ) == visited.end() ) {
	levelQChild.push( node->right );
	visited[ node->right ] = true;
      }
      if( visited.find( childParentMap[ node ] ) == visited.end() ) {
	levelQChild.push( childParentMap[ node ] );
	visited[ childParentMap[ node ] ] = true;
      }
    }
    levelQ = levelQChild;
    while( !levelQChild.empty() ) { levelQChild.pop(); }
    level++;
  }
  return levelQ;
}

int main() {
  Node *root = new Node( 3 );
  root->left = new Node( 5 );
  root->left->left = new Node( 6 );
  root->left->right = new Node( 2 );
  root->left->right->left = new Node( 7 );
  root->left->right->right = new Node( 4 );
  root->right = new Node( 1 );
  root->right->left = new Node( 0 );
  root->right->right = new Node( 8 );
  
  queue<Node *> k = getNodesKDistanceAway( root, root->left, 2 );
  while( !k.empty() ) {
    cout<< k.front()->data << " " << endl;
    k.pop();
  }
  return 0;
}
