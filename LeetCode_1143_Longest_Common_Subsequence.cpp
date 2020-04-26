/*
  1143. Longest Common Subsequence

  Given two strings text1 and text2, return the length of their longest common subsequence.

  Input: text1 = "abcde", text2 = "ace" 
  Output: 3  
  Explanation: The longest common subsequence is "ace" and its length is 3.
 */

/*
  Bottom-up DP utilizes a matrix m where we track LCS sizes for each combination of i and j.
  If a[i] == b[j], LCS for i and j would be 1 plus LCS till the i-1 and j-1 indexes.
  Otherwise, we will take the largest LCS if we skip a character from one of the string (max(m[i - 1][j], m[i][j - 1]).
 */

class Solution {
public:
  int longestCommonSubsequence( string text1, string text2 ) {
    int n=text1.length(), m=text2.length();
    if( n == 0 || m == 0 ) return 0;
        
    vector<vector<int>> lcs(n+1, vector<int>(m+1,0));

    for( int i=1; i<=n; i++ ) {
      for( int j=1; j<=m; j++ ) {
	if( text1[i-1] == text2[j-1] ) {
	  lcs[i][j] = lcs[i-1][j-1] + 1;
	} else {
	  lcs[i][j] = max( lcs[i-1][j], lcs[i][j-1] );
	}
      }
    }
    return lcs[n][m];
  }
};
