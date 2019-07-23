/*
    Approach to problem:
    Assume S = largeString, s = smallString;
    
    Iterate through the largeString backwards for each element 'e' of smallString.
    While doing so compute and store the nextOccurance of 'e' for each element of
    largeArray.
    The maximum of all these nextOccurance at index i will give the closure at
    index i.
  
    Compute the minimum diff between index and maximum value of nextOccurance to
    get min sub-string which contain all elements of smallString.
*/

class Solution {
public:
  string minWindow( string s, string t ) {
    if( s.size() == 0 ) return "";
    if( t.size() == 0 ) return s.substr(0,1);
    if( s.size() < t.size() ) return "";
        
    size_t size = s.length();
    vector<int> nextOccurance( size, 0 );
    for( int i=0; i < t.length(); i++ ) {
      // for each letter in 't' find the next occurence index
      int index = -1;
      for( int j=size-1; j >= 0; j-- ) {
	if( t[i] == s[j] )  {
	  index = j; 
	}
	if( index == -1 ) {
	  nextOccurance[j] = -1;
	} else if( nextOccurance[j] != -1 ) {
	  nextOccurance[j] = max( nextOccurance[j], index );
	}
      }
    }

    // Now, find the minimum closure
    int min = size;
    int start = -1;
    int end = -1;
    for( int i=size-1; i >= 0; i-- ) {
      if( nextOccurance[i] == -1 )
	continue;
            
      if( min > ( nextOccurance[i] - i ) ) {
	min = nextOccurance[i] - i;
	start = i;
	end = nextOccurance[i];
      }
    }
    if( start == -1 && end == -1 ) return "";
    return s.substr( start, end - start + 1 ); // substr( pos, length );
  }
};
