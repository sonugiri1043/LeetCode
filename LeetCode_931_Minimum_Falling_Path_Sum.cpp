/*931. Minimum Falling Path Sum
  Given a square array of integers A, we want the minimum sum of a falling path through A.
  A falling path starts at any element in the first row, and chooses one element from each row.
  The next row's choice must be in a column that is different from the previous row's column by at most one.
 
  Example 1:
  Input: [[1,2,3],[4,5,6],[7,8,9]]
  Output: 12
  Explanation: 
  The possible falling paths are:

  [1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
  [2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
  [3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
  The falling path with the smallest sum is [1,4,7], so the answer is 12
*/
  
/*
The minimum path to get to element A[i][j] is the minimum of A[i - 1][j - 1], A[i - 1][j] and A[i - 1][j + 1].
Starting from row 1, we add the minumum path to each element. The smallest number in the last row is the
miminum path sum.
Example:
[1, 2, 3]
[4, 5, 6] => [5, 6, 8]
[7, 8, 9] => [7, 8, 9] => [12, 13, 15]
  */
  int minFallingPathSum(vector<vector<int>>& A) {
  int n = A.size();
  vector<vector<int>> dp(n, vector<int>(n,0));
  // init first row of DP
  for( int i=0; i < n; i++ )
    dp[0][i] = A[0][i];
        
  for( int i=1; i < n; i++ ) {
    for( int j=0; j < n; j++ ) {
      int left = INT_MAX, right=INT_MAX;
      if( j > 0 ) left = dp[i-1][j-1];
      if( j < n-1 ) right = dp[i-1][j+1]; 
      dp[i][j] = A[i][j] + min( dp[i-1][j], min( left, right ) );
    }
  }
        
  int path = dp[n-1][0];
  for( auto p : dp[n-1] ) if( p < path ) path = p;
  return path;
}
