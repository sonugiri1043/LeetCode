/*
  Serialization is the process of converting a data structure or object into a sequence
  of bits so that it can be stored in a file or memory buffer, or transmitted across a
  network connection link to be reconstructed later in the same or another computer environment.

  Design an algorithm to serialize and deserialize a binary tree. There is no restriction
  on how your serialization/deserialization algorithm should work. You just need to ensure
  that a binary tree can be serialized to a string and this string can be deserialized
  to the original tree structure.
*/

class Codec {
public:
  // Encodes a tree to a single string.
  vector<TreeNode*> serialize( TreeNode* root ) {
    vector<TreeNode*> nodesInLevelOrder;
    if( !root ) return nodesInLevelOrder;
         
    // Use BFS
    queue<TreeNode*> q;
    q.push( root );
    nodesInLevelOrder.push_back( root );      
    TreeNode *currNode;
    while( !q.empty() ) {
      currNode = q.front(); q.pop();
      if( currNode->left ) {
	q.push( currNode->left );
	nodesInLevelOrder.push_back( currNode->left );
      } else {
	nodesInLevelOrder.push_back( NULL );
      }          
      if( currNode->right ) {
	q.push( currNode->right );
	nodesInLevelOrder.push_back( currNode->right );
      } else {
	nodesInLevelOrder.push_back( NULL );
      }
    }
    return nodesInLevelOrder;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize( vector<TreeNode*> nodesInLevelOrder ) {
    size_t size = nodesInLevelOrder.size();
    if( size == 0 ) return NULL;
    TreeNode *root = nodesInLevelOrder[0];
    TreeNode *curr;
    int index = 0;
    for( int i=0; i < size; i++ ) {
      curr = nodesInLevelOrder[i];
      if( curr ) {
	curr->left = nodesInLevelOrder[ ++index ];
      }
      if( curr ) {
	curr->right = nodesInLevelOrder[ ++index ];
      }
    }
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
