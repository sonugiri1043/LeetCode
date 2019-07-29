/*
  Given two strings s and t , write a function to determine if t is an anagram of s.

  Example 1:
  
  Input: s = "anagram", t = "nagaram"
  Output: true

  Example 2:
  Input: s = "rat", t = "car"
  Output: false

  Note: You may assume the string contains only lowercase alphabets.
 */

class Solution {
public:
  bool isAnagram(string s, string t) {
    if( s.length() != t.length() ) return false;
    vector<int> freq( 26, 0 );
    for( auto c : s ) {
      ++freq[ c - 'a' ];
    }
    for( auto c : t ) {
      --freq[ c - 'a' ];
      if( freq[ c - 'a'] < 0 ) return false;
    }
    return true;
  }
};
