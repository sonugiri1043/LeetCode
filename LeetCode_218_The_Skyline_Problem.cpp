/*
  218. The Skyline Problem
  https://leetcode.com/problems/the-skyline-problem/
 */

struct Point {
  int x, height;
  bool start;
  Point( int x, int h, bool s ) : x(x), height(h), start(s) {}
};

class Solution {
  static bool comparePoints( Point *p1, Point *p2 ) {
    /*
        - First order points based on their x co-ordinates.
        - If x xo-ordinate is same.
            - If both point has same start, then one with more height comes first.
            - If both have different start, then one with start comes first.
    */
    if( p1->x != p2->x ) {
      return p1->x < p2->x;
    }
    if( p1->start == p2->start ) {
      if( p1->start )
	return p2->height < p1->height;
      else
	return p2->height > p1->height;
    }
    if( !p1->start ) return false;
    return true;
  }
    
public:
  vector<vector<int>> getSkyline( vector<vector<int>>& buildings ) {
    vector<vector<int>> skyline; // result
    if( buildings.size() == 0 ) return skyline;
        
    vector<Point*> points;
    for( auto building : buildings ) {
      points.push_back( new Point( building[0], building[2], true ) );
      points.push_back( new Point( building[1], building[2], false ) );
    }
        
    // sort the points according to comparePoints
    sort( points.begin(), points.end(), comparePoints );
        
    /* maintain the height of all the active buildings
       ( building whose start and end intersect current point ) */
    map<int, int> heightMap;
    int maxHeight = 0;
    for( auto point : points ) {
      if( point->start ) {
	maxHeight = heightMap.empty() ? 0 : max( maxHeight, heightMap.rbegin()->first );
	heightMap[ point->height ]++;
                
	if( point->height > maxHeight ) {
	  maxHeight = point->height;
	  skyline.push_back( { point->x, maxHeight } );
	}
                
      } else {
	heightMap[ point->height ]--;
	if( heightMap[ point->height ] == 0 ) {
	  heightMap.erase( point->height );
                    
	  if( point->height == maxHeight ) {
	    maxHeight = heightMap.empty() ? 0 : heightMap.rbegin()->first;
	    skyline.push_back( { point->x, maxHeight } );  
	  }
                    
	}
      }
    }
    return skyline;
  }
};
