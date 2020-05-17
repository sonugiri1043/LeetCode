/*
  Palindrome Partitioning II [LeetCode 132]
  Given a string s, partition s such that every substring of the partition is a palindrome.
  Return the minimum cuts needed for a palindrome partitioning of s.

  Example:
  Input: "aab"
  Output: 1
  Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

/* Calculate and maintain 2 DP states:
   pal[i][j] , which is whether s[i..j] forms a palindrome
   
   d[i], which is the minCut for s[i..n-1]
   
   Once we comes to a pal[i][j] == true:
   
   if j==n-1, the string s[i..n-1] is a Palindrome, minCut is 0, d[i]=0;
   else: the current cut num ( first cut s[i..j] and then cut the rest
   s[j+1...n-1]) is 1 + d[j+1], compare it to the exisiting minCut num
   d[i], replace if smaller.
   d[0] is the answer.
*/

int minCut( string s ) {
  if( s.empty() ) return 0;
  
  int n = s.size();
  vector<vector<bool>> pal( n,vector<bool>(n,false) );
  // pal[i][j] = true => s[i...j] is palindrome
  vector<int> dp(n);
  // d[i] => minCut for s[i..n-1]
  
  for( int i=n-1; i >= 0; i-- ) {
    dp[i] = n-i-1;
    for( int j=i; j < n ; j++ )
      if( s[i] == s[j] && ( j-i < 3 || pal[i+1][j-1] ) ) {
	pal[i][j]=true;
	if( j == n-1 ) dp[i] = 0;
	else dp[i] = min( dp[i], 1 + dp[j+1] ); 
      }
  }
  return dp[0];
}
