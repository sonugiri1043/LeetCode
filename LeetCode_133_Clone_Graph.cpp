/*
  133. Clone Graph

  Given a reference of a node in a connected undirected graph, return a deep copy
  (clone) of the graph. Each node in the graph contains a val (int) and a list
  (List[Node]) of its neighbors.
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
  Node* cloneGraph(Node* node) {
    map<Node*, Node*> oldToNewNode;
    map<Node*, bool> visited;
    Node *curr;
        
    // Do BFS and create new nodes 
    queue<Node*> q;
    q.push( node );
    visited[ node ] = true;
    while( !q.empty() ) {
      curr = q.front();
      q.pop();
      oldToNewNode[ curr ] = new Node( curr->val, {} );       
      for( auto neighbor : curr->neighbors ) {
	if( visited.find( neighbor) == visited.end() ) {
	  q.push( neighbor );
	  visited[ neighbor ] = true;
	}
      }
    }
        
    // set neighbors for new nodes
    for( auto oldToNew : oldToNewNode ) {
      for( auto neighbor : oldToNew.first->neighbors ) {
	oldToNew.second->neighbors.push_back( oldToNewNode[neighbor] );
      }
    }
    return oldToNewNode[ node ];
  }
};
