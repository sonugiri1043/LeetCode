/*
  Integer Break [LeetCode 343]
  Given a positive integer n, break it into the sum of at least two positive
  integers and maximize the product of those integers. Return the maximum
  product you can get.

  Example:
  Input: 2
  Output: 1
  Explanation: 2 = 1 + 1, 1 × 1 = 1.
  Input: 10
  Output: 36
  Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

  Note: You may assume that n is not less than 2 and not larger than 58.
*/

int integerBreak( int n ) {
  // based on unbounded knapsack pattern 
  vector<int> dp(n + 1);
  dp[1] = 1;
  for( int i = 2; i <= n; i++ ) // all possible cuts
    for(int j = 1; j < i; j++ ) // all possible length of rods
      dp[i] = max( dp[i], ( max(j,dp[j]) )*( max( i-j, dp[ i-j] )));
  
  return dp[n];
}
