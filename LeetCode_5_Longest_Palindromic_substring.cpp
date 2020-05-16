/*
  Longest Palindromic Substring [LeetCode 5]
  Given a string s, find the longest palindromic substring in s.
  You may assume that the maximum length of s is 1000.
  
  Example :
  Input: "babad"
  Output: "bab"
  Note: "aba" is also a valid answer.
  
  Input: "cbbd"
  Output: "bb"
*/

string longestPalindrome( string s ) {
  int n = s.size();
  if( n <= 1 ) return s;
  
  // dp[i][j] indicates whether substring s starting at index i
  // and ending at j is palindrome
  vector<vector<bool>> dp( n, vector<bool>(n, false));
  
  for( int i=0; i<n; i++ ) dp[i][i] = true;
  
  string largest = s.substr( 0,1 );
  for( int i = n-1; i >= 0; i-- ) // keep increasing the possible palindrome string
    for( int j = i+1; j < n; j++ )
      // check if substring between (i,j) is palindrome
      // if window is less than or equal to 3, just end chars should match
      // if window is > 3, substring (i+1, j-1) should be palindrome too
      if( s[i] == s[j] && ( dp[i+1][j-1] || j-i < 3 ) ) {
	dp[i][j] = true;

	// update max palindrome string
	if( j - i + 1 > largest.size() )
	  largest = s.substr( i, j-i+1 );
      }

  return largest;
}

//Approach 2:
string longestPalindrome( string s ) {
  int n = s.size();
  if( n <= 1 ) return s;

  vector<vector<bool>> dp(n+1, vector<bool>(n,false));
  for( int i=0; i<n; i++ ) {
    dp[1][i] = true;
    dp[0][i] = true;
  }

  string largest = s.substr(0, 1);
  for( int i=2; i <= n; i++ ) // length
    for( int j=0; j < n - i + 1; j++ ) // start index
      if( s[j] == s[j+i-1] && dp[i-2][j+1] ) {
	dp[i][j] = true;
	if( largest.size() < i ) largest = s.substr( j, i );
      }

  return largest;
}
