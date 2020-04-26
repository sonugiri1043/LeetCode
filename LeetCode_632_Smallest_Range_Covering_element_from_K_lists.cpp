/*
  632. Smallest Range Covering Elements from K Lists

  You have k lists of sorted integers in ascending order. Find the smallest
  range that includes at least one number from each of the k lists.

  We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.
 */

/*
  Imagine you are merging k sorted arrays using a heap. Then everytime you pop the smallest
  element out and add the next element of that array to the heap. Keep doing this until one
  of the lists is exhausted, you will have the smallest range.
 */
class Solution {
public:    
  vector<int> smallestRange( vector<vector<int>>& nums ) {
    typedef vector<int>::iterator it;
        
    // comparator for minHeap
    struct comp {
      bool operator()( const pair<it,it>& p, const pair<it,it>& q ) {
	return *p.first > *q.first;
      }    
    };
    priority_queue< pair<it,it>, vector<pair<it,it>>, comp > minHeap;

    // add the first element from each list and update the inital range
    int low=INT_MAX, high=INT_MIN;
    for( int i=0; i<nums.size(); i++ ) {
      low =  min( low, nums[i][0] );
      high = max( high, nums[i][0] );
      minHeap.push( { nums[i].begin(), nums[i].end() } );
    }
        
    vector<int> res = { low, high }; // result
    while( minHeap.size() == nums.size() ) { // until we reach end of one of lists
      auto p = minHeap.top(); minHeap.pop();

      // move the iterator to next if end is reached then we quit otherwise push next
      ++p.first;
      if( p.first == p.second ) break;
            
      minHeap.push( p );
      low = *minHeap.top().first;
      high = max( high, *p.first );
            
      if( res[1] - res[0] > high - low )  res= { low, high };
    }
    return res;
  }
};
