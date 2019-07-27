/*
  70. Climbing Stairs

  You are climbing a stair case. It takes n steps to reach to the top.
  Each time you can either climb 1 or 2 steps. In how many distinct ways can
  you climb to the top?
  Note: Given n will be a positive integer.
 */

class Solution {
public:
  int climbStairs( int n ) {
    if( n <= 1 ) return 1;
    vector<int> steps( n, 0 );
    steps[0] = 1;
    steps[1] = 2;
    for( int i=2; i < n; i++ ) {
      steps[i] = steps[i-1] + steps[i-2];
    }
    return steps[n-1];
  }
};
