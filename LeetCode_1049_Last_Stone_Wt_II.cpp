/*
  We have a collection of rocks, each rock has a positive integer weight.

  Each turn, we choose any two rocks and smash them together.  Suppose the stones
  have weights x and y with x <= y.  The result of this smash is:

  If x == y, both stones are totally destroyed;
  If x != y, the stone of weight x is totally destroyed, and the stone of weight y
  has new weight y-x.
  At the end, there is at most 1 stone left.  Return the smallest possible weight
  of this stone (the weight is 0 if there are no stones left.)

  Example 1:
  Input: [2,7,4,1,8,1]
  Output: 1
  Explanation: 
  We can combine 2 and 4 to get 2 so the array converts to [2,7,1,8,1] then,
  we can combine 7 and 8 to get 1 so the array converts to [2,1,1,1] then,
  we can combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
  we can combine 1 and 1 to get 0 so the array converts to [1] then that's the optimal value.
 */

class Solution {
public:
  int lastStoneWeightII( vector<int>& stones ) {
    // Get total weight of all stones
    int totalWt=0;
    for( auto stoneWt : stones ) totalWt += stoneWt;
        
    // Divide all numbers into two groups,
    // minimum difference between the sum of two groups is the result
        
    /*
        0/1 Knapsack
        Possible items: 0,...,n-1 stones
        Possible Wt: 0,1,..., totalWt/2 */
    int n = stones.size();
    vector<vector<int>> dp( n+1, vector<int>( totalWt/2 + 1, 0 ) );
    for( int i=1; i<=n; i++ ) { // all items that can be picked
      for( int j=1; j <=totalWt/2; j++ ) {
	if( stones[i-1] > j ) // can't pick this stone as wt > j
	  dp[i][j] = dp[i-1][j];
	else
	  dp[i][j] = max( dp[i-1][j], stones[i-1] + dp[i-1][j - stones[i-1]] );
      }
    }
        
    /* check the max possible wt */
    int maxWt = 0;
    for( int i=1; i<=n; i++ )
      if( dp[i][totalWt/2] > maxWt )
	maxWt = dp[i][totalWt/2];
        
    return totalWt - 2*maxWt;
  }
};
