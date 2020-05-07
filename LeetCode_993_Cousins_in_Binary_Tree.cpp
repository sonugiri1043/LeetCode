/*
  Cousins in Binary Tree [LeetCode 993]
  In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
  Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
  We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
  Return true if and only if the nodes corresponding to the values x and y are cousins.
*/
  
// We store node->val => {depth, parent} mapping in hashtable and do a pre order traversal.
class Solution {
    void isCousinsHelper( TreeNode *node, int depth, TreeNode *parent,
			  unordered_map<int, pair<int,TreeNode*>> &levelParentDepth ) {
      if( !node ) return;
      levelParentDepth.insert( { node->val, { depth, parent } } );
      isCousinsHelper( node->left, depth+1, node, levelParentDepth );
      isCousinsHelper( node->right, depth+1, node, levelParentDepth );
    }
    
  public:
    bool isCousins( TreeNode* root, int x, int y ) {
      unordered_map<int, pair<int,TreeNode*> > levelParentDepth;
      isCousinsHelper( root, 0, nullptr, levelParentDepth );
        
      if( levelParentDepth.count(x) && levelParentDepth.count(y) )
	if( levelParentDepth[x].first == levelParentDepth[y].first &&
	    levelParentDepth[x].second !=  levelParentDepth[y].second )
	  return true;
      return false;
    }
  };
