/* 658. Find K Closest Elements
   Given a sorted array, two integers k and x, find the k closest elements
   to x in the array. The result should also be sorted in ascending order.
   If there is a tie, the smaller elements are always preferred.

   Example 1:
   Input: [1,2,3,4,5], k=4, x=3
   Output: [1,2,3,4]
   
   Example 2:
   Input: [1,2,3,4,5], k=4, x=-1
   Output: [1,2,3,4]
*/

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
  priority_queue< pair<int, int> > maxHeap;
  for( auto num : arr ) {
    if( maxHeap.size() < k) maxHeap.push( { abs(num - x), num } );
    else {
      if( maxHeap.top().first > abs( num - x) ) {
	maxHeap.push( { abs( num - x ), num  } );
	maxHeap.pop();
      }
    }
  }
        
  vector<int> result;
  while( !maxHeap.empty()){
    result.push_back( maxHeap.top().second );
    maxHeap.pop();
  }
  sort( result.begin(), result.end() );
  return result;
}

// TODO : DO it using binary search.
