/* Serialize and Deserialize a Binary Tree */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

struct TreeNode {
  int data;
  TreeNode *left, *right;
  
  TreeNode( int data ) : data( data ), left( nullptr ), right( nullptr ) {}
};

class Codec {
public:
  void serialize( TreeNode *node, string &encode ) {
    if( node == nullptr ) {
      encode += "-1";
      return;
    }
    encode += std::to_string( node->data );
    serialize( node->left, encode );
    serialize( node->right, encode );
  }

  TreeNode* deSerialize( string encode, int &startIndex ) {
    TreeNode *node = nullptr;
    if( startIndex > encode.length() ||
	encode[ startIndex ] == -1 ) {
      return node;
    }
    node = new TreeNode( encode[ startIndex ] );
    ++startIndex;
    node->left = deSerialize( encode, startIndex );
    node->right = deSerialize( encode, startIndex );
    return node;
  }
};

int main() {
  TreeNode *root = new TreeNode(20);
  root->left = new TreeNode(8);
  root->right = new TreeNode(22);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(12);
  root->left->right->left = new TreeNode(10);
  root->left->right->right = new TreeNode(14);

  Codec c;
  string encoded = "";
  c.serialize( root, encoded );
  cout<< encoded << endl;
  return 0;
}
