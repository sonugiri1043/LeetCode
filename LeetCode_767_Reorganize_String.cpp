/*
  767. Reorganize String
  Given a string S, check if the letters can be rearranged so that two characters that
  are adjacent to each other are not the same.

  If possible, output any possible result.  If not possible, return the empty string.

  Example 1:
  Input: S = "aab"
  Output: "aba"
  Example 2:
  Input: S = "aaab"
  Output:
*/

/*
The idea used here is similar to - https://leetcode.com/problems/rearrange-string-k-distance-apart

We need to arrange the characters in string such that each same character is K (k=1 here)
distance apart, where distance in this problems is time b/w two similar task execution.

Idea is to add them to a priority Q and sort based on the highest frequency.
And pick the task in each round of 'n' (n=2 here) with highest frequency. As you pick the task,
decrease the frequency, and put them back after the round.
*/

class Solution {
  public:
    string reorganizeString( string S ) {
      // Build char -> frequencymap
      unordered_map<char, int> charFreq;
      for( auto c : S )
	++charFreq[c];
        
      // Build a max heap based on frequency
      priority_queue< pair<int,char> > maxHeap;
      for( auto p : charFreq )
	maxHeap.push( { p.second, p.first } );
        
      string result="";
      while( !maxHeap.empty() ) {
	if( maxHeap.size() == 1 && maxHeap.top().first > 1 ) {
	  // only one element left with with frequency > 1
	  result = "";
	  break;
	}
        
	/* pop the most frequent element (lets say 'x' ) and one more element ('y')
               to be placed adjacent to 'x'. 
               push 'x' and 'y' again to max stack if their remaining frequency > 0
	*/
	queue< pair<int,char> > tmpQueue;
	int n = 2; // window size 2
	while( !maxHeap.empty() && n-- > 0 ) {
	  auto p = maxHeap.top(); maxHeap.pop();
	  result += p.second;
	  --p.first;
	  if( p.first > 0 ) tmpQueue.push( p );
	} 
	while( !tmpQueue.empty() ) {
	  maxHeap.push( tmpQueue.front() );
	  tmpQueue.pop();
	}
      }
      return result;
    }
  }
