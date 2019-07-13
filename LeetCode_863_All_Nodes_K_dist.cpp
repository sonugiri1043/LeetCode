/*
  https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

  863. All Nodes Distance K in Binary Tree

  We are given a binary tree (with root node root), a target node, and an integer value K.
  Return a list of the values of all nodes that have a distance K from the target node.
  The answer can be returned in any order.

  Example 1:
  Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
  Output: [7,4,1]
  
  Explanation: 
  The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

  Note that the inputs "root" and "target" are actually TreeNodes.
  The descriptions of the inputs above are just serializations of these objects.
 
  Note:
  The given tree is non-empty.
  Each node in the tree has unique values 0 <= node.val <= 500.
  The target node is a node in the tree.
  0 <= K <= 1000.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  void getParent( TreeNode *node, unordered_map<TreeNode*, TreeNode*> &parent,
		  unordered_map< TreeNode *, bool> &visited ) {
    if( node == NULL ) {
      return;
    }
    if( node->left ) {
      parent[ node->left ] = node;
      visited[ node->left ] = false;
      getParent( node->left, parent, visited );
    }
    if( node->right ) {
      parent[ node->right ] = node;
      visited[ node->right ] = false;
      getParent( node->right, parent, visited );
    }
  }
    
  vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    // init visited array and get the parent of all nodes
    unordered_map< TreeNode*, TreeNode* > nodeParent;
    unordered_map< TreeNode*, bool> visited;
    nodeParent[ root ] = NULL;
    visited[ root ] = false;
    getParent( root, nodeParent, visited );
        
    // Do BFS starting from target node
    queue< TreeNode* > parents;
    queue< TreeNode *> children;
    parents.push( target );
    visited[ target ] = true;
    TreeNode *curr = NULL;
    while( K ) {
      K--;
      while( !parents.empty() ) {
	curr = parents.front();
	parents.pop();
	if( curr->left && !visited[ curr->left ] ) {
	  visited[ curr->left ] = true;
	  children.push( curr->left );
	}
	if( curr->right && !visited[ curr->right ] ) {
	  visited[ curr->right ] = true;
	  children.push( curr->right );
	}
	if( nodeParent[ curr ] && !visited[ nodeParent[ curr ] ] ) {
	  visited[ nodeParent[ curr] ] = true;
	  children.push( nodeParent[curr] );
	}
      }
      parents = children;
      // clear children queue
      while( !children.empty() )
	children.pop();
    }
        
    // get the result in vector
    vector<int> kDistNodes;
    while( !parents.empty() ) {
      curr = parents.front();
      parents.pop();
      kDistNodes.push_back( curr->val );
    }
    return kDistNodes;
  }
};
