/*
  Best Time to Buy and Sell Stock with Cooldown [LeetCode 309]
  Say you have an array for which the ith element is the price of a given stock on day i.
  Design an algorithm to find the maximum profit. You may complete as many transactions as
  you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
  
  You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
  After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

  Example:
  Input: [1,2,3,0,2]
  Output: 3 
  Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/

/*
  buy[i] = max(sell[i-2]-price, buy[i-1])
  sell[i] = max(buy[i-1]+price, sell[i-1])
*/
int maxProfit(vector<int>& prices) {
  int n = prices.size();
  if( n <= 1 ) return 0;
  
  vector<int> buy( n, 0 ), sell( n, 0 );
  buy[0] = -1*prices[0];
  for( int i=1; i < n; i++ ) {
    if( i > 1)
      buy[i] = max( buy[i-1], sell[i-2] - prices[i] );
    else
      buy[i] = max( buy[i-1], -1*prices[i] );
    sell[i] = max( sell[i-1], buy[i-1] + prices[i] );
  }
  return sell[n-1];
}
