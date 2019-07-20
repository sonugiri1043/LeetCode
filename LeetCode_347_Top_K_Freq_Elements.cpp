/*
  347. Top K Frequent Elements

  Given a non-empty array of integers, return the k most frequent elements.

  Example 1:
  Input: nums = [1,1,1,2,2,3], k = 2
  Output: [1,2]

  Example 2:
  Input: nums = [1], k = 1
  Output: [1]
*/

#define p pair<int, int>

struct myComparator {
  bool operator() ( const p & p1, const p & p2 ) { 
    return p1.second > p2.second; 
  }
}; 

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map< int, int > freq; // key -> freq map
    for( auto num : nums ) {
      if( freq.find( num ) == freq.end() ) {
	freq[ num ] = 1;
      } else {
	freq[ num ] += 1;
      }
    }
        
    // build min heap of size k
    priority_queue< p, vector<p>, myComparator > q;
    for( auto f : freq ) {
      if( q.size() < k ) {
	q.push( f );
      } else {
	if( f.second > q.top().second ) {
	  q.pop();
	  q.push( f );
	}
      }
    }
        
    // compile the result
    vector< int > topk;
    while( !q.empty() ) {
      topk.push_back( q.top().first );
      q.pop();
    }
    return topk;
  }
};
