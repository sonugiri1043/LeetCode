/*
  221. Maximal Square
  Given a 2D binary matrix filled with 0's and 1's, find the largest square
  containing only 1's and return its area.

  Example:
  Input: 

  1 0 1 0 0
  1 0 1 1 1
  1 1 1 1 1
  1 0 0 1 0

  Output: 4
 */

/*
  We initialize another matrix (dp) with the same dimensions as the original one initialized with all 0’s.

  dp(i,j) represents the side length of the maximum square whose bottom right corner is the cell with index (i,j) in the original matrix.

  Starting from index (0,0), for every 1 found in the original matrix, we update the value of the current element as

  dp(i,j)=min(dp(i−1,j),dp(i−1,j−1),dp(i,j−1))+1.
  We also remember the size of the largest square found so far. In this way, we traverse the original matrix once and find out the required maximum size. This gives the side length of the square (say maxsqlen ). The required result is the area maxsqlen^2.
 */

int maximalSquare( vector<vector<char>>& matrix ) {
  int m = matrix.size();
  if( m == 0  )
    return 0;
  int n = matrix[0].size();
  int maxSquareLen = 0;
  vector<vector<int>> dp(m+1, vector<int>(n+1,0));
  for( int i=1; i <= m; i++ ) {
    for( int j=1; j <= n; j++ ) {
      if( matrix[i-1][j-1] == '1')
	dp[i][j] = min( min( dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] ) + 1;

      if( dp[i][j] > maxSquareLen ) maxSquareLen = dp[i][j];
    }
  }
  return maxSquareLen*maxSquareLen;
}
