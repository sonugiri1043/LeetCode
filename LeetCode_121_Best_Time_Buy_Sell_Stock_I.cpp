/*
  121. Best time to but and sell stock

  Say you have an array for which the ith element is the price of a given stock
  on day i.
  If you were only permitted to complete at most one transaction (i.e., buy one
  and sell one share of the stock), design an algorithm to find the maximum profit.

  Note that you cannot sell a stock before you buy one.
  Example 1:
  Input: [7,1,5,3,6,4]
  Output: 5
  Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
  Not 7-1 = 6, as selling price needs to be larger than buying price.
 */

class Solution {
public:
  int maxProfit( vector<int>& prices ) {
    size_t size = prices.size();
    if( size <= 1 ) return 0;
        
    int maxDiffPrice = prices[size-1];
    int maxProfit=0;
    // store the maximum price seen so far while scanning the prices from right
    // maxProfit is the max difference between prices and max price seen so far
    for( int i=prices.size() - 2; i >= 0; i-- ) {
      maxDiffPrice = max( maxDiffPrice, prices[i] );
      if( maxProfit < ( maxDiffPrice - prices[i] ) )
	maxProfit = maxDiffPrice - prices[i];
    }
    return maxProfit;
  }
};
