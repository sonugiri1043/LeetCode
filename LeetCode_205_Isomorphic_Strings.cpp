/*
  205. Isomorphic Strings

  Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
Note:
You may assume both s and t have the same length.
 */

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> charMap;
    for( auto i = 0; i < s.length(); i++ ) {
      if( charMap.find(s[i]) == charMap.end() ) {
	charMap[ s[i] ] = t[i];
      } else {
	if( charMap[ s[i] ] != t[i] )
	  return false;
      } 
    }
        
    unordered_map<char, char> charMap1;
    for( auto i = 0; i < t.length(); i++ ) {
      if( charMap1.find(t[i]) == charMap1.end() ) {
	charMap1[ t[i] ] = s[i];
      } else {
	if( charMap1[ t[i] ] != s[i] )
	  return false;
      } 
    }
        
    return true;
  }
};
