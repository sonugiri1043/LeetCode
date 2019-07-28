/*
  22. Generate Parentheses

  Given n pairs of parentheses, write a function to generate all combinations of well-formed
  parentheses.
  For example, given n = 3, a solution set is:
  [
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
  ]
 */

class Solution {
  void helper( string paren, int open, int close,
	       int total, vector<string> &result ) {
    if( close > open || open > total || close > total ) return;
        
    if( open == close && close == total ) {
      result.push_back( paren );    
    }
    helper( paren + "(", open + 1, close, total, result );
    helper( paren + ")", open, close + 1, total, result );
  }
    
public:
  vector<string> generateParenthesis( int n ) {
    vector<string> result;
    helper( "", 0, 0, n, result);
    return result;
  }
};
