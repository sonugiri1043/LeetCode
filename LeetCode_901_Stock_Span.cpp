/*
  Online Stock Span [LeetCode 901]
  Write a class StockSpanner which collects daily price quotes for some stock,
  and returns the span of that stock's price for the current day.
  The span of the stock's price today is defined as the maximum number of consecutive days
  (starting from today and going backwards) for which the price of the stock was less than
  or equal to today's price.
  For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85],
  then the stock spans would be [1, 1, 1, 2, 1, 4, 6].
*/

class StockSpanner {
  int day;
  stack< pair<int, int> > s;
public:
  StockSpanner() { this->day = 0; }
  
  int next( int price ) {
    ++day;
    int count;
    if( s.empty() ) {
      s.push( { price, day } );
      count = 1;
    } else if( s.top().first > price ) {
      count = day - s.top().second;
      s.push( { price, day } );
    } else {
      while( !s.empty() && price >= s.top().first ) 
	s.pop();
      if( s.empty() ) count = day;
      else count = day - s.top().second;
      
      s.push( {price, day } );
    }
    return count;
  }
};


