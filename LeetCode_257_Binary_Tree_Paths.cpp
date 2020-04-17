/*
  257. Binary Tree Paths

  Given a binary tree, return all root-to-leaf paths.
  Note: A leaf is a node with no children.

  Example:
  Input:

   1
 /   \
2     3
 \
  5

  Output: ["1->2->5", "1->3"]
  Explanation: All root-to-leaf paths are: 1->2->5, 1->3
 */

class Solution {
public:
  void dfs( TreeNode *node, string path, vector<string> &paths ) {
    if( !node ) return;
    if( !node->left && !node->right ) {
      paths.push_back( path + to_string( node->val ) );
      return;
    }

    dfs( node->left, path + to_string( node->val ) + "->", paths );
    dfs( node->right, path + to_string( node->val ) + "->", paths );
  }
    
  vector<string> binaryTreePaths( TreeNode* root ) {
    vector<string> paths;
    if( !root ) return paths;
        
    string path = "";
    dfs( root, path, paths );
    return paths;
  }
};
