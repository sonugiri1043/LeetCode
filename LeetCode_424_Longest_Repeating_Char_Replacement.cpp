/*
  424. Longest Repeating Character Replacement

  Given a string s that consists of only uppercase English letters,
  you can perform at most k operations on that string. In one operation,
  you can choose any character of the string and change it to any other uppercase
  English character. Find the length of the longest substring containing all repeating
  letters you can get after performing the above operations.

  Input:
  s = "ABAB", k = 2
  Output:
  4

  Explanation:
  Replace the two 'A's with two 'B's or vice versa.

  Input:
  s = "AABABBA", k = 1
  Output:
  4
 */

class Solution {
public:
  int characterReplacement( string s, int k ) {
    // largest substring with character other than maxFreq <= k
    int windowStart = 0, maxLen = INT_MIN;
    unordered_map<char, int> freq;
    int maxFreq = 0; // highest value in freq table
    for( int windowEnd=0; windowEnd < s.length(); windowEnd++ ) {
      freq[ s[windowEnd] ]++; // extend the window
      maxFreq = max( maxFreq, freq[ s[windowEnd] ] );
      if( windowEnd - windowStart + 1 - maxFreq <= k ) {
	// valid window, replacement chars are atmost k
	maxLen = max( maxLen, windowEnd - windowStart + 1 );
      } else {
	// shrink the window if no of replacement chars are greater than 'k'
	freq[ s[windowStart] ]--;
	windowStart++;
      }
    }
    return maxLen == INT_MIN ? 0 : maxLen;
  }
};
