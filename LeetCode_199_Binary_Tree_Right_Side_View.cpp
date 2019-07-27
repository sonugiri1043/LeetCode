/*
  Given a binary tree, imagine yourself standing on the right side of it,
  return the values of the nodes you can see ordered from top to bottom.

  Example:
  Input: [1,2,3,null,5,null,4]
  Output: [1, 3, 4]

  Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
 */

class Solution {
public:
  vector<int> rightSideView( TreeNode* root ) {
    vector<int> result;
    if( !root ) return result;
        
    vector<TreeNode*> level1;
    vector<TreeNode*> level2;
    level1.push_back( root );
    while( level1.size() > 0 ) {
      result.push_back( level1[ level1.size() - 1 ]->val );
      for( auto node : level1 ) {
	if( node->left )  level2.push_back( node->left );
	if( node->right ) level2.push_back( node->right );
      }
      level1 = level2;
      level2.clear();
    }
    return result;
  }
};


class Solution {
  void rightViewHelper( TreeNode* node, int level, vector<int> & result ) {
    if( !node ) return;
    if( result.size() < level ) result.push_back( node->val );     
    if( node->right )  rightViewHelper( node->right, level + 1, result );
    if( node->left )   rightViewHelper( node->left, level + 1, result );
  }
    
public:
  vector<int> rightSideView( TreeNode* root ) {
    vector<int> result;
    rightViewHelper( root, 1, result );
    return result;
  }
};
