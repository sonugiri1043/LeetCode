/*
  131. Palindrome Partitioning
  Given a string s, partition s such that every substring of the partition
  is a palindrome.

  Return all possible palindrome partitioning of s.
  Example:
  Input: "aab"
  Output:
  [ ["aa","b"],
  ["a","a","b"]]
 */

class Solution {
public:
  vector<vector<string>> partition( string s ) {
    vector<vector<string>> result;
    vector<string> curr;
    backtrack( result, curr, 0, s );
    return result;
  }
    
private:
  void backtrack( vector<vector<string>>& result, vector<string>& curr,
		  int start, string& s ) {
    if( start == s.length() ) {
      result.push_back( curr );
      return;
    }
    for( int i=start; i < s.size(); i++ ) {
      if( isPalindrome( s, start, i ) ) {
	curr.push_back( s.substr( start, i - start + 1 ) );
	backtrack( result, curr, i+1, s );
	curr.pop_back();
      }
    }
  }
    
  bool isPalindrome( string& s, int start, int end ) {
    while( start < end ) {
      if( s[start] != s[end] ) return false;
      start++;
      end--;
    }
    return true;
  }
};
