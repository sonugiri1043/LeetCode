/*
  502. IPO
  You are given several projects. For each project i, it has a pure profit Pi and a
  minimum capital of Ci is needed to start the corresponding project. Initially, you
  have W capital. When you finish a project, you will obtain its pure profit and the
  profit will be added to your total capital.
  
  To sum up, pick a list of at most k distinct projects from given projects to maximize
  your final capital, and output your final maximized capital.

  Example 1:
  Input: k=2, W=0, Profits=[1,2,3], Capital=[0,1,1].

  Output: 4
  
  Explanation: Since your initial capital is 0, you can only start the project indexed 0.
  After finishing it you will obtain profit 1 and your capital becomes 1.
  With capital 1, you can either start the project indexed 1 or the project indexed 2.
  Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
  Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
*/

/*
  The idea is each time we find a project with max profit and within current
  capital capability.

  1. Create ( capital, profit ) pairs and put them into minHeap minHeapOnCapital.
  2. Keep polling pairs from minHeapOnCapital until there are no more project with
     capital less than current capital capability. Put them into maxHeap maxHeapProfit.
  3. Poll one from maxHeapProfit, it's guaranteed to be the project with max profit
     and within current capital capability. Add the profit to capital W.
  4. Repeat step 2 and 3 till finish k steps or no suitable project (maxHeapProfit.isEmpty()).

  Time Complexity: O( n log n )
  • Each project is inserted/move out of capital queue once.
  • Each project can be inserted/moved out of profit queue once.
*/

class Solution {
    #define p pair<int,int>
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<int> maxHeapProfit; // max heap on profit
        priority_queue< p, vector<p>, greater<p> > minHeapOnCapital; // min heap on capital
        for( int i=0; i < Profits.size(); i++ ) {
            minHeapOnCapital.push( make_pair( Capital[i], Profits[i] ) );
        }
        
        int profit = W;
        while( k ) {
            while( !minHeapOnCapital.empty() && profit >= minHeapOnCapital.top().first ) {
                maxHeapProfit.push( minHeapOnCapital.top().second );
                minHeapOnCapital.pop();
            }  
            if( maxHeapProfit.empty() ) break;
          
            k--;
            profit += maxHeapProfit.top();
            maxHeapProfit.pop(); 
        }
        return profit;
    }
};
