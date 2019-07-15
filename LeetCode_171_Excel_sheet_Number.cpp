/*
  Given a column title as appear in an Excel sheet, return its corresponding column number.

  For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...

  Example 1:
    Input: "A"
    Output: 1

  Example 2:
    Input: "AB"
    Output: 28
 */

class Solution {
public:
  int titleToNumber(string s) {
    int colNo = 0;
    for( int i = 0; i < s.length(); i++ ) {
      colNo = colNo*26 + ( s[i] - 'A' + 1 );
    }
    return colNo;
  }
};
