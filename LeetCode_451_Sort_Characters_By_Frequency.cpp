/*
  451. Sort Characters by Frequency
  Given a string, sort it in decreasing order based on the frequency of characters.

  Example 1:
  Input:
  "tree"
  Output:
  "eert"

  Explanation:
  'e' appears twice while 'r' and 't' both appear once.
  So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

  Example 2:
  Input:
  "Aabb"
  Output:
  "bbAa"
  Explanation:
  "bbaA" is also a valid answer, but "Aabb" is incorrect.
  Note that 'A' and 'a' are treated as two different characters.
 */

class Solution {
  static bool compareInt( pair<int, char> p1, pair<int,char> p2 ) {
    return p1.first > p2.first;
  }
    
public:
  string frequencySort( string s ) {
    vector< pair<int,char> > freq( 256 );
    for( int i=0; i < 256; i++ ) {
      freq[i] = make_pair( 0, i );
    }
    for( auto c : s ) {
      freq[c].first++;
    }
    sort( freq.begin(), freq.end(), compareInt );
    string result = "";
    for( auto f : freq ) {
      if( f.first == 0 ) break;
      while( f.first ) {
	result += f.second;
	--f.first;
      }
    }
    return result;
  }
};
