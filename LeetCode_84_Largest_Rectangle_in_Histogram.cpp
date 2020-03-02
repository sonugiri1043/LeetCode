/*
  84. Largest Rectangle in Histogram

  Given n non-negative integers representing the histogram's bar height
  where the width of each bar is 1, find the area of largest rectangle in the histogram.

  Approach:
  For every bar ‘x’, we calculate the area with ‘x’ as the smallest bar in the rectangle.
  We need to know index of the first smaller (smaller than ‘x’) bar on left of ‘x’ and
  index of first smaller bar on right of ‘x’.  Let us call these indexes as ‘left index’
  and ‘right index’ respectively.

  We traverse all bars from left to right, maintain a stack of bars. Every bar is pushed
  to stack once. A bar is popped from stack when a bar of smaller height is seen. When a 
  bar is popped, we calculate the area with the popped bar as smallest bar. How do we get
  left and right indexes of the popped bar – the current index tells us the ‘right index’
  and index of previous item in stack is the ‘left index’.
*/

class Solution {
  int largestRectangleArea( vector<int> heights ) {
    int maxArea = 0, area = 0;
    heights.push_back(0);
    int n = heights.size();
    stack<int> s;
    
    int i = 0;
    while( i < n ) {
      if( s.empty() || heights[ s.top() ] <= heights[i] ) {
	s.push( i );
	i++;
      } else {
	int topIndex = s.top(); s.pop();
	int l = s.empty() ? -1 : s.top();
	area = heights[topIndex] * (i - l - 1);
	maxArea = max( maxArea, area );
      }
    }
    
    return maxArea;
  }
};
