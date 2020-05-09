/*
  Valid Perfect Square[LeetCode 367] 
  Given a positive integer num, write a function which returns True if num is a perfect
  square else False.
  Note: Do not use any built-in library function such as sqrt.
*/

bool isPerfectSquare(int num) {
  int start = 1, end = num;
  while( start <= end ) {
    long mid = start + (end-start)/2;
    if( mid*mid == num ) return true;
    else if( mid*mid > num ) end = mid - 1;
    else start = mid + 1;
  }
  return false;
}											  }
