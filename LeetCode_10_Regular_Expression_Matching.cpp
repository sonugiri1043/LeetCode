/*
  Regular Expression Matching [LeetCode 10]**
  Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
  '.' Matches any single character.
  '*' Matches zero or more of the preceding element.

  The matching should cover the entire input string (not partial).
  Note:
  s could be empty and contains only lowercase letters a-z.
  p could be empty and contains only lowercase letters a-z, and characters like . or *.

  Example:
  Input:
  s = "aa"
  p = "a"
  Output: false
  Explanation: "a" does not match the entire string "aa".
  
  Input:
  s = "aa"
  p = "a*"
  Output: true
  Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
  
  Input:
  s = "ab"
  p = ".*"
  Output: true
  Explanation: ".*" means "zero or more (*) of any character (.)".

  Input:
  s = "aab"
  p = "c*a*b"
  Output: true
  Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
  
  Input:
  s = "mississippi"
  p = "mis*is*p*."
  Output: false
*/

/*
  The most critical observation is that "x*" can either match empty string, or at least one x.
  dp[i][j] denotes if s[0...i-1] is valid for pattern p[0...j-1].
  Recurrence relation:
  1. If p[j] == s[i] : dp[i][j] = dp[i-1][j-1];
  2. If p[j] == '.'  : dp[i][j] = dp[i-1][j-1];
  3. If p[j] == '*'  : 
  here are two sub conditions:
    1. if p[j-1] != s[i] : dp[i][j] = dp[i][j-2]  //in this case, a* only counts as empty
    2. if p[j-1] == s[i] or p[j-1] == '.':
          dp[i][j] = dp[i-1][j]    //in this case, a* counts as multiple a 
       or dp[i][j] = dp[i][j-1] // in this case, a* counts as single a
       or dp[i][j] = dp[i][j-2] // in this case, a* counts as empty

  Consider following example
  s='aab', p='c*a*b'

      c * a * b 
    0 1 2 3 4 5
  0 y
a 1
a 2
b 3

So what about the first column? for and empty pattern p="" only thing that is valid is an empty string s="" and that is already our dp[0][0] which is true. That means rest of `dp[i][0]' is false.
s='aab', p='c*a*b'

      c * a * b 
    0 1 2 3 4 5
  0 y
a 1 n
a 2 n
b 3 n

What about the first row? In other words which pattern p matches empty string s=""? The answer is either an empty pattern p="" or a pattern that can represent an empty string such as p="a*", p="z*" or more interestingly a combiation of them as in p="abc*". Below for loop is used to populate dp[0][j]. Note how it uses previous states by checking dp[0][j-2]

for (int j=2; j<=p.length(); j++) {
       dp[0][j] = p.charAt(j-1) == '*' && dp[0][j-2]; 
}

At this stage our matrix has become as follows: Notice dp[0][2] and dp[0][4] are both true because p="c*" and p="ca" can both match an empty string.
s='aab', p='c*a*b'

      c * a * b 
    0 1 2 3 4 5
  0 y n y n y n
a 1 n
a 2 n
b 3 n

So now we can start our main iteration. It is basically the same, we will iterate all possible s lengths (i) for all possible p lengths (j) and we will try to find a relation based on previous results. Turns out there are two cases.
(p.charAt(j-1) == s.charAt(i-1) || p.charAt(j-1) == '.') if the current characters match or pattern has . then the result is determined by the previous state dp[i][j] = dp[i-1][j-1]. Don't be confused by the charAt(j-1) charAt(i-1) indexes using a -1 offset that is because our dp array is actually one index bigger than our string and pattern lenghts to hold the initial state dp[0][0]
  if p.charAt(j-1) == '*' then either it acts as an empty set and the result is dp[i][j] = dp[i][j-2] or (s.charAt(i-1) == p.charAt(j-2) || p.charAt(j-2) == '.') current char of string equals the char preceding * in pattern so the result is dp[i-1][j]
So here is the final state of matrix after we evaluate all elements:
  s='aab', p='c*a*b'

      c * a * b 
    0 1 2 3 4 5
  0 y n y n y n
a 1 n n n y y n
a 2 n n n n y n
b 3 n n n n n y
*/

bool isMatch(string s, string p) {
      int m = s.size(), n = p.size();
      vector<vector<bool>> dp( m+1, vector<bool>( n+1, false ) );

      dp[0][0] = true; // when empty pattern and empty string
      // match row for pattern with empty text
      for( int j=2; j<=n; j++ ) {
	dp[0][j] = p[j-1] == '*' && dp[0][j-2]; 
      }

      for( int i=1; i<=m ; i++ ) {
	for( int j=1; j<=n ; j++) {
	  // if there is a match
	  if( p[j-1] == s[i-1] || p[j-1] == '.' ) 
	    dp[i][j] = dp[i-1][j-1];
	  else if( p[j-1] == '*' ) {
	    // 0 occurrence of character prev to '*'
	    // OR
	    // pattern and text matches till the last occurrence
	    dp[i][j] = dp[i][j-2];
	    if( s[i-1] == p[j-2] || p[j-2] == '.')
	      dp[i][j] |= dp[i-1][j];
	  }
	}
      }
      return dp[m][n]; 
    }
// Time and space complexity are O(m * n).
