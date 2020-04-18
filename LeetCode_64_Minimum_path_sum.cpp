/*
  64. Minimum Path Sum
  Given a m x n grid filled with non-negative numbers, find a path from top
  left to bottom right which minimizes the sum of all numbers along its path.

  Note: You can only move either down or right at any point in time.
  Example:
  Input:
  [
  [1,3,1],
  [1,5,1],
  [4,2,1]
  ]
  Output: 7
  Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 */

class Solution {
public:
  int minPathSum( vector<vector<int>>& grid ) {
    int m = grid.size(), n = grid[0].size(); 
    vector<vector<int> > pathSum( m, vector<int>( n, grid[0][0]) );
    // update 1st row
    for (int i = 1; i < m; i++)
      pathSum[i][0] = pathSum[i-1][0] + grid[i][0];
    // update first column
    for (int j = 1; j < n; j++)
      pathSum[0][j] = pathSum[0][j-1] + grid[0][j];

    // pathSum[i][j] = min( pathSum[i-1][j] + grid[i],  pathSum[i][j-1] + grid[i] ) 
    for (int i = 1; i < m; i++)
      for (int j = 1; j < n; j++)
	pathSum[i][j]  = min( pathSum[i-1][j], pathSum[i][j-1]) + grid[i][j];
        
    return pathSum[m-1][n-1];
  }
};
