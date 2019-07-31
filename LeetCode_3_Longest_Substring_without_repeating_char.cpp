/*
  Given a string, find the length of the longest substring without repeating characters.

  Example 1:
  Input: "abcabcbb"
  Output: 3 
  Explanation: The answer is "abc", with the length of 3. 

  Example 2:
  Input: "bbbbb"
  Output: 1
  Explanation: The answer is "b", with the length of 1.

  Example 3:
  Input: "pwwkew"
  Output: 3
  Explanation: The answer is "wke", with the length of 3. 
  Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

class Solution {
public:
  int lengthOfLongestSubstring( string s ) {
    set<char> substr;
    int maxUniqueLen = 0;
    int left=0, right=0; // sliding window of all elements in set
    for( int i=0; i < s.length(); i++ ) {
      if( substr.count( s[i] ) == 1 ) {
	// Remove all elements till prev s[i] then insert new s[i]
	while( s[left] != s[i] ) {
	  substr.erase( s[left] );
	  ++left;
	}
	substr.erase( s[left] );
	++left;
      }
      right++;
      substr.insert( s[i] );
      maxUniqueLen = max( right-left, maxUniqueLen ); 
    }
    return maxUniqueLen;
  }
};
