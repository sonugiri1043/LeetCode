/*
  114. Flatten Binary Tree to Linked List
  Given a binary tree, flatten it to a linked list in-place.
 */

class Solution {
  void getPreorder( TreeNode *root, vector<TreeNode*> &preorder ) {
    if( !root ) return;
    preorder.push_back( root );
    getPreorder( root->left, preorder );
    getPreorder( root->right, preorder );
  }
    
public:
  void flatten( TreeNode* root ) {
    if( !root ) return;
        
    vector<TreeNode*> preorder;
    getPreorder( root, preorder );
    size_t size = preorder.size();
    for( int i=0; i < size-1; i++ ) {
      preorder[i]->left = NULL;
      preorder[i]->right = preorder[i+1];
    }
  }
};
