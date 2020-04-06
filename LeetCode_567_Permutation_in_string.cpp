/*
  Given two strings s1 and s2, write a function to return true if s2 contains
  the permutation of s1. In other words, one of the first string's permutations
  is the substring of the second string.

  Example 1:
  Input: s1 = "ab" s2 = "eidbaooo"
  Output: True
  Explanation: s2 contains one permutation of s1 ("ba").

  Example 2:
  Input:s1= "ab" s2 = "eidboaoo"
  Output: False
*/

class Solution {
public:
  bool checkInclusion( string s1, string s2 ) {
    unordered_map<char, int> freqS1, freqWindowS2;
    for( auto c : s1 ) ++freqS1[c]; // freq table for s1
        
    int windowStart = 0;
    // keep a window of size 's1.length()' and move 1 step each time
    for( int windowEnd=0; windowEnd < s2.length(); windowEnd++ ) {
      char c = s2[windowEnd];
      freqWindowS2[ c ]++; // extend the window
      if( windowEnd >= s1.length() ) {
	c = s2[ windowEnd - s1.length() ];
	freqWindowS2[c]--; // shrink the window
	if( freqWindowS2[c] == 0 ) freqWindowS2.erase(c);
      }
      // if valid window
      if( freqWindowS2 == freqS1 )
	return true;
    }
    return false;
  }
};
