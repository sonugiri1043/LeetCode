/*
  Given a string containing digits from 2-9 inclusive, return all possible letter
  combinations that the number could represent.

  A mapping of digit to letters (just like on the telephone buttons) is given below.
  Note that 1 does not map to any letters.

  Example:
  Input: "23"
  Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
  Note:
  Although the above answer is in lexicographical order, your answer could be in any
  order you want.
 */

class Solution {
  unordered_map<char, string> init() {
    unordered_map< char, string > digitToChar;
    digitToChar['2'] = "abc";
    digitToChar['3'] = "def";
    digitToChar['4'] = "ghi";
    digitToChar['5'] = "jkl";
    digitToChar['6'] = "mno";
    digitToChar['7'] = "pqrs";
    digitToChar['8'] = "tuv";
    digitToChar['9'] = "wxyz";
    return digitToChar;
        
  }
  void dfs( unordered_map<char, string> digitToChar,
            queue<string> &result, string digits ) {
    if( digits == "" ) return;
    int size = result.size();
    for( int i=0; i < size; i++ ) {
      string s = result.front(); result.pop();
      for( auto c : digitToChar[ digits[0] ] ) {
	result.push( s + c );
      }
    }
    dfs( digitToChar, result, digits.substr( 1 ) );
  }
    
public:
  vector<string> letterCombinations( string digits ) {
    vector< string > results;
    if( digits == "" ) return results;

    unordered_map< char, string > digitToChar = init();
    queue< string > result;
    result.push( "" );
    dfs( digitToChar, result, digits );

    while( !result.empty() ) {
      results.push_back( result.front() );
      result.pop();
    }
    return results;
  }
};
