/*
  973. K Closest Points to Origin
  
  We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
  (Here, the distance between two points on a plane is the Euclidean distance.)

  You may return the answer in any order.  The answer is guaranteed to be unique
  (except for the order that it is in.)
 */

class Solution {
public:
  int dist( vector<int> &point ) {
    return point[0]*point[0] + point[1]*point[1];    
  }
    
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    typedef pair<int, int> pi;
        
    int distance;
    priority_queue< pi > maxHeap;
    for( int i=0; i < points.size(); i++ ) {
      distance = dist( points[i] );
      if( maxHeap.size() < K )
	maxHeap.push( { distance, i } );
      else if( distance < maxHeap.top().first ) {
	maxHeap.push( { distance, i } );
	maxHeap.pop();
      }
    }
        
    vector<vector<int>> result;
    while( !maxHeap.empty() ) {
      result.push_back( points[ maxHeap.top().second ] );
      maxHeap.pop();
    }
    return result;
  }
};
