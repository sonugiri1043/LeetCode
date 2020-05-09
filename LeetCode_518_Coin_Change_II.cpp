/*
  Coin Change 2 [LeetCode 518]
  You are given coins of different denominations and a total amount of money.
  Write a function to compute the number of combinations that make up that amount.
  You may assume that you have an infinite number of each kind of coin.

  Input: amount = 5, coins = [1, 2, 5]
  Output: 4
  Explanation: there are four ways to make up the amount:
  5=5
  5=2+2+1
  5=2+1+1+1
  5=1+1+1+1+1
  Input: amount = 3, coins = [2]
  Output: 0
  Explanation: the amount of 3 cannot be made up just with coins of 2.
  Input: amount = 10, coins = [10] 
  Output: 1
*/

int change( int amount, vector<int>& coins ) {
  int n = coins.size();
  // unbonded knapsack
  vector<vector<int>> dp( n + 1, vector<int>( amount + 1 ,0 ) );

  dp[0][0]=1;// this helps when amount remaining == coin value to add 1
  for( int i=1; i <= n; i++  ) { // items
    dp[i][0] = 1;
    for( int j=1; j <= amount; j++ ) // weights
      if( coins[i-1] > j )
	dp[i][j] = dp[i-1][j];
      else
	dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
  }
  return dp[n][amount];
}

// space optimized
int change( int amount, vector<int>& coins ) {
    // unbonded knapsack
    vector<int> dp( amount + 1, 0 );

    dp[0] = 1; // this helps when amount remaining == coin value to add 1
    for( auto coin : coins )
      for( int i=1; i <= amount; i++ )
	if( coin <= i )
	  dp[i] = dp[i] + dp[i-coin];

    return dp[amount];
  }

