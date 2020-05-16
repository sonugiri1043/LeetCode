/*
  Longest Palindromic Subsequence [LeetCode 516]
  Given a string s, find the longest palindromic subsequence's length in s.
  You may assume that the maximum length of s is 1000.

  Example:
  Input:
  "bbbab"
  Output:
  4
  One possible longest palindromic subsequence is "bbbb".
  
  Input:
  "cbbd"
  Output:
  2
  One possible longest palindromic subsequence is "bb".
*/

//DP Based on the length of palindromic subsequence
int longestPalindromeSubseq( string s ) {
  int n = s.size();
  vector<vector<int>> dp( n+1, vector<int>(n, 0));
  
  for( int i = 0; i < n; i++ )
    dp[1][i] = 1;

  for( int i = 2; i <= n; i++ ) // length
    for( int j = 0; j < n-i+1; j++ ) // start index
      if( s[j] == s[j+i-1] )
	dp[i][j] = dp[i-2][j+1] + 2;
      else
	dp[i][j] = max( dp[i-1][j], dp[i-1][j+1] );
  
  return dp[n][0];
}

/*
  dp[i][j]: the longest palindromic subsequence's length of substring(i, j),
  here i, j represent left, right indexes in the string
  
  State transition:
  dp[i][j] = dp[i+1][j-1] + 2 if s[i] == s[j]
  otherwise, dp[i][j] = max( dp[i+1][j], dp[i][j-1] )
  Initialization: dp[i][i] = 1
*/
int longestPalindromeSubseq( string s ) {
  int n = s.size();
  vector<vector<int>> dp( n, vector<int>(n, 0));
  
  for( int i=0; i<n; i++ ) dp[i][i] = 1;
  
  for( int i = n-1; i >= 0; i-- ) {
    for( int j = i+1; j < n; j++ ) {
      if( s[i] == s[j] )
	dp[i][j] = dp[i+1][j-1] + 2;
      else
	dp[i][j] = max( dp[i+1][j], dp[i][j-1] );
    }
  }
  return dp[0][n-1];
}
