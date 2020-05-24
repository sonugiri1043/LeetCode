/*
  Wildcard Matching [LeetCode 44]
  Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
  '?' Matches any single character.
  '*' Matches any sequence of characters (including the empty sequence).
  
  The matching should cover the entire input string (not partial).
  Note:
  s could be empty and contains only lowercase letters a-z.
  p could be empty and contains only lowercase letters a-z, and characters like ? or *.
  Example:
  Input:
  s = "aa"
  p = "a"
  Output: false
  Explanation: "a" does not match the entire string "aa".

  Input:
  s = "aa"
  p = "*"
  Output: true
  Explanation: '*' matches any sequence.

  Input:
  s = "cb"
  p = "?a"
  Output: false
  Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
  
  Input:
  s = "adceb"
  p = "*a*b"
  Output: true
  Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
  
  Input:
  s = "acdcb"
  p = "a*c?b"
  Output: false
*/
  
// Similar to Regular Expression Matching [LeetCode 10]
bool isMatch(string s, string p) {
  int m = s.size(), n = p.size();
  vector<vector<bool>> dp( m+1, vector<bool>( n+1, false ) );
  
  // init
  dp[0][0] = true;
  for( int j=1; j<=n; j++ ) {
    dp[0][j] = p[j-1] == '*' && dp[0][j-1]; 
  }
  
  for( int i=1; i<=m ; i++ ) {
    for( int j=1; j<=n ; j++) {
      if( p[j-1] == s[i-1] || p[j-1] == '?' ) 
	dp[i][j] = dp[i-1][j-1];
      else if( p[j-1] == '*' ) {
	dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i-1][j-1];
      }
    }
  }
  return dp[m][n];
}
