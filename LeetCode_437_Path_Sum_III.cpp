/*
  437. Path Sum III

  You are given a binary tree in which each node contains an integer value.
  Find the number of paths that sum to a given value.

  The path does not need to start or end at the root or a leaf, but it must go downwards.

  root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
 */

class Solution {
public:
    void dfs( TreeNode *node, vector<int>& pathSums, int &noOfPaths, int sum ) {
        if( !node ) return;
        
        // check if any existing path leads to desired sum
        for( int i=0; i < pathSums.size(); i++ ) {
            pathSums[i] += node->val;
            if( pathSums[i] == sum ) noOfPaths++;
        }
        // check if current node is equal to desired sum and start a new path
        pathSums.push_back( node->val );
        if( node->val == sum ) noOfPaths++; 
        
        dfs( node->left, pathSums, noOfPaths, sum );
        dfs( node->right, pathSums, noOfPaths, sum );
        
        // backtrack
        pathSums.pop_back();
        for( int i=0; i < pathSums.size(); i++ ) {
            pathSums[i] -= node->val;
        }
    }
    
    int pathSum( TreeNode* root, int sum ) {
        int noOfPaths = 0;
        vector<int> pathSums;
        dfs( root, pathSums, noOfPaths, sum );
        return noOfPaths;
    }
};
