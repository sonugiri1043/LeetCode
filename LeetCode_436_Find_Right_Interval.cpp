/*
  436. Find Right Interval

  Given a set of intervals, for each of the interval i, check if there exists
  an interval j whose start point is bigger than or equal to the end point of
  the interval i, which can be called that j is on the "right" of i.

  For any interval i, you need to store the minimum interval j's index, which
  means that the interval j has the minimum start point to build the "right" relationship
  for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally,
  you need output the stored value of each interval as an array.

  Note:
  You may assume the interval's end point is always bigger than its start point.
  You may assume none of these intervals have the same start point.
 */

vector<int> findRightInterval( vector<vector<int>>& intervals ) {
  map< int, int> hash; // start-point to index map
  for( int i=0; i < intervals.size(); i++ ) {
    hash[ intervals[i][0] ] = i;
  }
        
  vector<int> result;
  map<int, int>::iterator it;
  for( int i=0; i < intervals.size(); i++ ) {
    it = hash.lower_bound( intervals[i][1] );
    if( it == hash.end() ) result.push_back( -1 );
    else result.push_back( (*it).second );
  }
  return result;
}
