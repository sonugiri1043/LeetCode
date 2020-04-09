/*
There are a number of spherical balloons spread in two-dimensional space.
For each balloon, provided input is the start and end coordinates of the
horizontal diameter. Since it's horizontal, y-coordinates don't matter and
hence the x-coordinates of start and end of the diameter suffice. Start is
always smaller than end. There will be at most 104 balloons.

An arrow can be shot up exactly vertically from different points along the x-axis.
A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend.
There is no limit to the number of arrows that can be shot. An arrow once shot keeps
travelling up infinitely. The problem is to find the minimum number of arrows that must
be shot to burst all balloons.
*/

/*

sort pairs based on the first element of a pair.
start from the last pair. Each time we choose point.first() as shot place, remove overlap pairs from the array. Repeat it until we exhaust the array.
-----------------
   -----
   ↑      -----
 2nd shot   ---------
            ↑
         1st shot

1. Sort balloons in increasing order of the start position.
2. Scan the sorted pairs from last,
  To shoot the last ballon we need to shoot at start position to cover as many as ballons as possible.
    skip all the ballons whose end points like ahead of this start position (since they will get busted.)
  If end point lies before start pos( non-overlapping ) then update the startPosition and increment the arrow count.
*/
  int findMinArrowShots( vector<vector<int>>& points ) {
  if( points.size() == 0 ) return 0;
        
  // sort the points by start
  auto comp = []( vector<int> p1, vector<int> p2 ) { return p1[0] < p2[0]; };
  sort( points.begin(), points.end(), comp );
        
  int result = 1, arrowPos = points[points.size() - 1][0];
  for( int i=points.size()-2; i >= 0; i-- ) {
    if( points[i][1] >= arrowPos ) {
      continue;
    }
    result++;
    arrowPos = points[i][0];
  }
  return result;
}
