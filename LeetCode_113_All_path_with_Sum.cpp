/*
  Given a binary tree and a sum, find all root-to-leaf paths where each
  path's sum equals the given sum.
 */

class Solution {
  void dfs( TreeNode *node, int sum, vector<int>& path,
	    vector<vector<int>>& paths ) {
    if( !node ) return;
    path.push_back( node->val );
    if( !node->left && !node->right && sum == node->val ) {
      paths.push_back( path );
    } 
    dfs( node->left, sum - node->val, path, paths );
    dfs( node->right, sum - node->val, path, paths );
    path.pop_back();
  }
public:
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector< vector<int> > paths;
    vector<int> path;
    dfs( root, sum, path, paths );
    return paths;
  }
};
