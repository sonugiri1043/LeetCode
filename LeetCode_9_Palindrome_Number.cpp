/*
  9. Palindrome Number

  Determine whether an integer is a palindrome. An integer is a palindrome when
  it reads the same backward as forward.

  Example 1:
  Input: 121
  Output: true

  Example 2:
  Input: -121
  Output: false
  Explanation: From left to right, it reads -121. From right to left, it becomes 121-.
  Therefore it is not a palindrome.
 */

class Solution {
public:
  long reverseInt( int x ) {
    long y = 0;
    while( x > 0 ) {
      y = y*10 + x%10;
      x = x/10;
    }
    return y;
  }
  bool isPalindrome( int x ) {
    if( x < 0 ) return false;
    if( reverseInt( x ) == x ) return true;
    return false;
        
  }
};
