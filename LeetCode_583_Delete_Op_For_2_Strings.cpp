/*
  Delete Operation for Two Strings [LeetCode 583]
  Given two words word1 and word2, find the minimum number of steps required
  to make word1 and word2 the same, where in each step you can delete one
  character in either string.
  
  Example:
  Input: "sea", "eat"
  Output: 2
  Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
*/

/*
  To make them identical, just find the longest common subsequence.
  The rest of the characters have to be deleted from the both the strings,
  which does not belong to the longest common subsequence.
*/

int minDistance( string word1, string word2 ) {
  int m = word1.size(), n = word2.size();
  vector<vector<int>> dp( m+1, vector<int>(n+1, 0));
  
  for( int i=1; i<=m; i++ )
    for( int j=1; j<=n; j++ )
      if( word1[i-1] == word2[j-1] )
	dp[i][j] = 1 + dp[i-1][j-1];
      else
	dp[i][j] = max( dp[i][j-1], dp[i-1][j] );

  return (m+n - 2*dp[m][n]);
}
