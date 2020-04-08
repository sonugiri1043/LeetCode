/*
  Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

  You may assume that the intervals were initially sorted according to their start times.

  Example 1:
  Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
  Output: [[1,5],[6,9]]

  Example 2:
  Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
  Output: [[1,2],[3,10],[12,16]]
  Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10]
*/

class Solution {
public:
  vector<vector<int>> insert( vector<vector<int>>& intervals, vector<int>& newInterval ) {         vector<vector<int>> front, back, allIntervals;  
    allIntervals.push_back( newInterval );
    for( auto interval : intervals ) {
      if( interval[1] < allIntervals.back()[0] ) {
	// interval is non-verlapping and before newInterval
	front.push_back( interval );
      } else if( interval[0] > allIntervals.back()[1] ) {
	// interval is non-verlapping and after newInterval
	back.push_back( interval );
      } else {
	// intervals overlap
	allIntervals.back()[0] = min( allIntervals.back()[0], interval[0] );
	allIntervals.back()[1] = max( allIntervals.back()[1], interval[1] );
      }
    }
    front.insert( front.end(), allIntervals.begin(), allIntervals.end() );
    front.insert( front.end(), back.begin(), back.end() );
    return front;
  }
};
