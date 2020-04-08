
class Solution {
  /* Which interval would be the best first (leftmost) interval to keep?
       One that ends first, as it leaves the most room for the rest. So take one with
       smallest end, remove all the bad ones overlapping it, and repeat
       (taking the one with smallest end of the remaining ones). For the overlap test,
       just keep track of the current end, initialized with negative infinity.*/
public:
  int eraseOverlapIntervals( vector<vector<int>>& intervals ) {
    if( intervals.size() == 0 ) return 0;
        
    // sort the intervals based on their start points
    auto comp = [](vector<int> i1, vector<int> i2) { return i1[0] < i2[0]; };
    sort( intervals.begin(), intervals.end(), comp );
        
    int nonOverlapping = 0;
    int previousNonOverlappingIntervalEnd = INT_MIN;
    for( int i=0; i<intervals.size(); i++ ) {
      if( intervals[i][0] >= previousNonOverlappingIntervalEnd  ) {
	nonOverlapping++;
	previousNonOverlappingIntervalEnd = intervals[i][1];
      } else
	previousNonOverlappingIntervalEnd = min( previousNonOverlappingIntervalEnd,
						 intervals[i][1] );
    }
        
    return intervals.size() - nonOverlapping;
  }
};
