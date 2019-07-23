/*
  7. Reverse Integer
  Given a 32-bit signed integer, reverse digits of an integer.

  Example 1:
  Input: 123
  Output: 321

  Example 2:
  Input: -123
  Output: -321

  Example 3:
  Input: 120
  Output: 21
 */

/* INT_MAX =  2147483647
   INT_MIN = -2147483648 */
class Solution {
public:
  int reverseInt( int x ) {
    long y = 0;
    while( x > 0 ) {
      y = y*10 + x%10;
      x = x/10;
    }
    // check for overflow
    if( y > INT_MAX ) return 0;
    return y;
  }
    
  int reverse( int x ) {
    if( x < 0 ) {
      if( x == INT_MIN ) 
	return 0; // since INT_MIN can't be represented in reverse order
      return -1 * reverseInt( x * -1 );
    } else {
      return reverseInt( x );
    }
  }
};
