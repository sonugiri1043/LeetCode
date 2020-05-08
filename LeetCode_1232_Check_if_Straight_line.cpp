/*
  Check If It Is a Straight Line [LeetCode 1232]
  You are given an array of coordinates, coordinates[i] = [x, y], where [x, y]
  represents the coordinate of a point. Check if these points make a straight
  line in the XY plane.
*/

  bool checkStraightLine( vector<vector<int>>& coordinates ) {        
    int dY = coordinates[1][1] - coordinates[0][1];
    int dX = coordinates[1][0] - coordinates[0][0];     
    for( int i=2; i < coordinates.size(); i++ ) {
      auto p = coordinates[i];
      if( dX*(p[1] - coordinates[0][1]) != dY*(p[0] - coordinates[0][0]) )
	return false;
    }
    return true;
  }
