/*692. Top K Frequent Words

  Given a non-empty list of words, return the k most frequent elements.
  
  Your answer should be sorted by frequency from highest to lowest. If two
  words have the same frequency, then the word with the lower alphabetical order comes first.
  
  Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
  Output: ["i", "love"]

  Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
  Output: ["the", "is", "sunny", "day"]
  Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
  with the number of occurrence being 4, 3, 2 and 1 respectively.
*/

//MaxHeap O( nlogk )
  class Solution {
  public:
    typedef pair<int,string> pi;
    struct comp {
      bool operator()( pi a, pi b ) {
	return b.first > a.first || (b.first == a.first && b.second < a.second);
      }
    };
    vector<string> topKFrequent( vector<string>& words, int k ) {
      unordered_map<string, int> m;
      for( auto word : words )
	++m[word];

      priority_queue< pi,vector<pi>, comp > maxHeap;
      for( auto p : m )
	maxHeap.push( {p.second, p.first} );
        
      vector<string> result;
      while( k-- > 0 ) {
	result.push_back( maxHeap.top().second );
	maxHeap.pop();
      }
      return result;
    }
  };

//O(n) bucket sort

vector<string> topKFrequent( vector<string>& words, int k ) {
  unordered_map<string, int> m;
  for( string word : words )   // build number to frequency map
    ++m[word];
        
  // aggregate all the numbers into respective frequency bucket
  vector<set<string>> buckets( words.size() + 1 ); 
  for( auto p : m )
    buckets[p.second].insert( p.first );

  // build result
  vector<string> result;
  for( int i = buckets.size() - 1; i >= 0 && result.size() < k; --i ) {
    for( auto word : buckets[i] ) {
      result.push_back( word );
      if( result.size() == k )
	break;
    }
  }
  return result;
}
