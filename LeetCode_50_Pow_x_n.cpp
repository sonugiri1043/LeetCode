/*
  Implement pow(x, n), which calculates x raised to the power n (xn).

  Example 1:
  Input: 2.00000, 10
  Output: 1024.00000

  Example 2:
  Input: 2.10000, 3
  Output: 9.26100

  Example 3:
  Input: 2.00000, -2
  Output: 0.25000
  Explanation: 2-2 = 1/22 = 1/4 = 0.25
 */

double myPow( double x, int n ) {
  if( n == 0 ) return 1;
  if( n == 1 ) return x;
  if( n < 0 ) {
    if( n == INT_MIN ) {
      n = INT_MAX;
      return x/( myPow(x,n) );  
    } else {
      n = -n;
      return 1/myPow( x, n );
    }
  }
  double temp = myPow( x, n/2 );
  if( n % 2 == 0 )  return temp*temp;
  else  return x*temp*temp;
}
