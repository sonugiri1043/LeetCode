/*
  Jump Game II [LeetCode 45]**
  Given an array of non-negative integers, you are initially positioned at the first index of the array.
  Each element in the array represents your maximum jump length at that position.
  Your goal is to reach the last index in the minimum number of jumps.
  Example:
  Input: [2,3,1,1,4]
  Output: 2
  Explanation: The minimum number of jumps to reach the last index is 2.
  Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

  int jump( vector<int>& nums ) {
  int n = nums.size();
  vector<int> dp( n, INT_MAX );
  dp[0] = 0;
  for( int i=1; i < n; i++ ) {
    for( int j=0; j < i; j++ ) {
      if( nums[j] + j >= i )
	dp[i] = min( dp[i], 1 + dp[j] );   
    }
  }
  return dp[n-1];
}

// Using BFS **
class Solution {
public:
  /* Try to change this problem to a BFS problem,
      where nodes in level i are all the nodes that can be reached in i-1th jump.
      for example. 2 3 1 1 4 , is
      2||
      3 1||
      1 4 ||

     clearly, the minimum jump of 4 is 2 since 4 is in level 3.
  */
  int jump(vector<int> A ) {
    int n = A.size();
    if( n < 2 ) return 0;
    int level=0, currentMax=0, i=0, nextMax=0;

    while( i <= currentMax ) { // nodes count of current level
      level++;
      for( ; i<=currentMax; i++ ) {
	// traverse current level , and update
	// the max reach of next level
	nextMax = max( nextMax, A[i] + i );
	
	// if last element is in level+1,  then the min jump=level 
	if( nextMax >= n-1 ) return level;
      }
      currentMax = nextMax;
    }
    return 0;
  }
};
