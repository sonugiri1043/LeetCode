/*
  56. Merge Intervals
  Given a collection of intervals, merge all overlapping intervals.

  Example 1:
  Input: [[1,3],[2,6],[8,10],[15,18]]
  Output: [[1,6],[8,10],[15,18]]
  Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

  Example 2:
  Input: [[1,4],[4,5]]
  Output: [[1,5]]
  Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 */

class Solution {
  static bool compareIntervals( vector<int> i1, vector<int> i2 ) {
    return i1[0] < i2[0];    
  }
    
public:
  vector<vector<int>> merge( vector<vector<int>>& intervals ) {
    if( intervals.empty() ) return {};
        
    sort( intervals.begin(), intervals.end(), compareIntervals );
    vector< vector<int> > result;
    result.push_back( intervals[0] );
    for( int i=1; i < intervals.size(); i++ ) {
      int n = result.size();
      if( result[n-1][1] >= intervals[i][0] )
	result[n-1][1] = max( intervals[i][1], result[n-1][1] );
      else
	result.push_back( intervals[i] ); 
    }
    return result;
  }
};
