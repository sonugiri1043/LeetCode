/*
  650. 2 Keys Keyboard
  Initially on a notepad only one character 'A' is present. You can perform two
  operations on this notepad for each step:

  Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
  Paste: You can paste the characters which are copied last time.

  Given a number n. You have to get exactly n 'A' on the notepad by performing the
  minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

  Example 1:
  Input: 3
  Output: 3
  Explanation:
  Intitally, we have one character 'A'.
  In step 1, we use Copy All operation.
  In step 2, we use Paste operation to get 'AA'.
  In step 3, we use Paste operation to get 'AAA'.
 */

/*
    We look for a divisor d so that we can make d copies of (n / d) to get n
    The process of making d copies takes d steps (1 step of Copy All and d - 1 steps of Paste)

    Best case occurs for perfect square numbers, worst occurs for prime;
    where dp[i] = i if i is prime.
*/
int minSteps( int n ) {
  vector<int> dp( n+1, 0);
  for( int i=2; i <= n; i++ ) {    
    dp[i] = i;
    for( int j=i/2; j >= 2; j-- ) {
      if( i%j == 0 ) {
	dp[i] = dp[j] + i/j;
	break;
      }
    }
  }
  return dp[n];
}
