/*
  637. Average of Levels in Binary Tree
  Given a non-empty binary tree, return the average value of the nodes
  on each level in the form of an array.
*/

class Solution {
public:
  vector<double> averageOfLevels( TreeNode* root ) {
    vector<double> avgs;
    queue<TreeNode*> nodes;
    nodes.push( root );
    double sum = root->val;
    while( !nodes.empty() ) {
      avgs.push_back( sum/nodes.size() );
      sum = 0;
      int size = nodes.size();
      for( int i=0; i < size; i++ ) {
	TreeNode *node = nodes.front(); nodes.pop();
	if( node->left ) {
	  nodes.push( node->left );
	  sum += node->left->val;
	}
	if( node->right ) { 
	  nodes.push( node->right );
	  sum += node->right->val;
	}
      }
    }
    return avgs;
  }
};
