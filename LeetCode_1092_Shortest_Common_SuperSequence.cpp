/*
  Shortest Common Supersequence [LeetCode 1092]
  Given two strings str1 and str2, return the shortest string that has both
  str1 and str2 as subsequences.  If multiple answers exist, you may return
  any of them.
  
  (A string S is a subsequence of string T if deleting some number of characters
  from T (possibly 0, and the characters are chosen anywhere from T) results in the string S.)
  
  Example 1:
  Input: str1 = "abac", str2 = "cab"
  Output: "cabac"
  Explanation: 
  str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
  str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
  The answer provided is the shortest such string that satisfies these properties.
*/
class Solution {
public:
  /*
    Idea: The result string should contain all characters of s1 and s2
    discarding the common ones. -> S1+S2 - LCS
    
    Here is the approach using dynamic programming:
    
    Compute the LCS using Dynamic Programming.
    We will start processing the table using the last cell till i > 0 or j > 0
    1) Check if s1[i-1] == s2[j-1]. If equal, we must add this character to the
       result string only once
    2) If not equal, then find the maximum of dp[i-1][j] and dp[i][j-1]
       ( this is how you had calculated LCS length first ) , start moving in the max
     direction after inserting the character to the result string. Moving in max
     direction means discarding that character of the string that has not contributed
     in LCS. But still inserting in the final string because it will contribute in
     SuperSequence.
     i.e
     if( dp[i-1][j] > dp[i][j-1] ) {
        res.push_back( s1[i-1] );
        i--;
      }
     3) Compute till i>0 && j>0. If any of the string is left i.e if i>0 or j>0 then
     add its characters to the result. This means that we copied 1 complete string but
     other is still remaining.
     
     We have got the required string but stored all the characters in reverse order.
     So, just reverse the result and you will get the final answer.
    */
  string shortestCommonSupersequence( string str1, string str2 ) {
    int m = str1.length(), n = str2.length();
    
    vector<vector<int>>  dp( m+1, vector<int> (n+1, 0));
    int i, j;
    // calculate LCS
    for( i=1; i<=m; i++ )
      for( j=1; j<=n; j++ )
	if( str1[i-1] == str2[j-1] )
	  dp[i][j] = 1 + dp[i-1][j-1];
	else
	  dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
    
    // build the string from lcs
    i=m;
    j=n;
    string str = "";
    while( i>0 && j>0 ) {
      if( dp[i][j] == dp[i-1][j] ) {
	  str += str1[i-1];
	  i--;
      } else if( dp[i][j] == dp[i][j-1] ) {
	str += str2[j-1];
	j--;
      } else {
	str += str1[i-1];
	i--;
	j--;
      }
    }    
    while( i-- > 0 )
      str += str1[i];
    while( j-- > 0 )
      str += str2[j];
    
    reverse( str.begin(), str.end() );
    return str;
  }
};
