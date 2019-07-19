/*
  69. Sqrt(x)

  Implement int sqrt(int x).

  Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

  Since the return type is an integer, the decimal digits are truncated and only
  the integer part of the result is returned.

  Example 1:
  Input: 4
  Output: 2

  Example 2:
  Input: 8
  Output: 2
  Explanation: The square root of 8 is 2.82842..., and since 
  the decimal part is truncated, 2 is returned.
 */

class Solution {
public:
  int mySqrt( int x ) {
    if( x == 0 ) return 0;
        
    long low=1, high=x, mid, product; // 'long' avoids overflow
    while( low <= high ) {
      mid = ( low + high )/2;
            
      product = mid*mid;
      if( product == x ) {
	return mid;
      }
            
      if( product < x ) {
	low = mid + 1;
      } else {
	high = mid - 1 ;
      }
    }
    // because we could have incremented mid when 'res < x'
    if( mid * mid > x ) mid = mid - 1;
    return mid;
  }
};
