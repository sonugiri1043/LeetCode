/*
  Min Cost Climbing Stairs [LeetCode 746]
  On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed). 

  Once you pay the cost, you can either climb one or two steps. You need to find minimum
  cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
  
  Input: cost = [10, 15, 20]
  Output: 15
  Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
  
  Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
  Output: 6
  Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
*/

/*
                           __________
		      ___ | Final step
                 ___ | 20
            ___ | 15
_________ | 10
First step
*/
  int minCostClimbingStairs( vector<int>& cost ) {
  int n = cost.size();
  vector<int> dp( n + 1, 0 );
  dp[0]=cost[0];
  dp[1]=cost[1];
  for( int i=2; i <= n; i++ ) {
    dp[i] = min( dp[i-1], dp[i-2] ) + (i == n ? 0 : cost[i]);
  }
  return dp[n];
}
