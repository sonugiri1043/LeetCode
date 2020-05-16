/*
  Palindromic Substrings [LeetCode 647]
  Given a string, your task is to count how many palindromic substrings
  in this string.
  The substrings with different start indexes or end indexes are counted
  as different substrings even if they consist of the same characters.
  
  Example 1:
  Input: "abc"
  Output: 3
  Explanation: Three palindromic strings: "a", "b", "c".

  Input: "aaa"
  Output: 6
  Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".  
*/

int countSubstrings( string s ) {
  int n = s.size();
  // dp[i][j] = substring starting at i and ending at j
  vector<vector<bool>> dp(n, vector<bool>(n, false));
  int count = 0;
  
  // init
  for( int i=0; i < n; i++ ) {
    dp[i][i] = true;
    ++count;
  }
  
  for( int i = n-1; i >= 0; i-- ) {
    for( int j=i+1; j < n; j++ ) {
      // check if substring between (i,j) is palindrome
      // if window is less than or equal to 3, just end chars should match
      // if window is > 3, substring (i+1, j-1) should be palindrome too
      if( s[i] == s[j] && ( j - i < 3 || dp[i+1][j-1] ) ) {
	++count;
	dp[i][j] = true;
      }
    }
  }
  return count;
}


// DP Based on length of substring
int countSubstrings( string s ) {
  int n = s.size();
  // dp[i][j] i=> length of substr, j => startIndex
  vector<vector<bool>> dp( n + 1, vector<bool>(n, false ) );
  int count = 0;

  // init for len of substr = 1 and substr = 2
  for( int j=0; j < n; j++ ) {
    ++count;
    dp[1][j] = true;
    dp[0][j] = true;
  }
  
  for( int i=2; i <= n; i++ )
    for( int j=0; j<n-i+1; j++ )
      if( s[j] == s[j+i-1] && dp[i-2][j+1] ) {
	++count;
	dp[i][j] = true;
      }
  return count;
}
