/*
  438. Find All Anagrams in a String

  Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

  Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab"
 */

class Solution {
public:
  vector<int> findAnagrams( string s, string p ) {
    vector<int> startIndexes;
    unordered_map<char, int> pFreq, pFreqInS;
    for( auto c : p ) pFreq[c]++;
        
    int windowSize = p.length();
    // maintain freq of chars in moving window of size p.length()
    for( int windowEnd=0; windowEnd < s.length(); windowEnd++ ) {
      // extend the window by one char at windowEnd
      char c = s[windowEnd];
      if( pFreq.find( c ) != pFreq.end() ) {
	pFreqInS[ c ]++;
      }
      // shrink the window by one char at windowStart
      if( windowEnd >= windowSize ) {
	char c = s[ windowEnd - windowSize ];
	if( pFreq.find( c ) != pFreq.end() ) {
	  pFreqInS[ c ]--;
	}
      }
      // both p and s.substr [ windowStart, windowEnd ] are anagrams
      if( pFreq == pFreqInS ) {
	startIndexes.push_back( windowEnd - p.length() + 1 );     
      }
    }
    return startIndexes;
  }
};
