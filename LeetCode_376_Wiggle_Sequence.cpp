/*
  Wiggle Subsequence [LeetCode 376]
  A sequence of numbers is called a wiggle sequence if the differences between successive
  numbers strictly alternate between positive and negative. The first difference (if one exists)
  may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.
  
  For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are
  alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle
  sequences, the first because its first two differences are positive and the second because
  its last difference is zero.
  
  Given a sequence of integers, return the length of the longest subsequence that is a wiggle
  sequence. A subsequence is obtained by deleting some number of elements (eventually, also
  zero) from the original sequence, leaving the remaining elements in their original order.
  
  Example:
  Input: [1,7,4,9,2,5]
  Output: 6
  Explanation: The entire sequence is a wiggle sequence.
  Input: [1,17,5,10,13,15,10,5,16,8]
  Output: 7
  Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
  Input: [1,2,3,4,5,6,7,8,9]
  Output: 2
*/

/*  
    up[i] is the length of a longest wiggle subsequence of { nums[0], ... , nums[i] },
    with a positive difference between its last two numbers.

    down[i] is the length of a longest wiggle subsequence of {nums[0],...,nums[i]},
    with a negative difference between its last two numbers.

    Base case:
    At i=0, there is only one number and we can use it as a subsequence, i.e up[0]=down[0]=1
*/
int wiggleMaxLength( vector<int>& nums ) {
    int n = nums.size();
    if( n == 0 ) return 0;

    vector<int> up( n, 0 ), down( n, 0 );
    // init
    up[0] = 1, down[0] = 1;
    for( int i=1; i < n; i++ )
      if( nums[i] > nums[i-1] ) {
	// we can use nums[i] to make a longer subsequence of type up
	up[i] = down[i-1] + 1;
	down[i] = down[i-1];
      } else if( nums[i] < nums[i-1] ) {
	// we can use nums[i] to make a longer subsequence of type down
	up[i] = up[i-1];
	down[i] = up[i-1] + 1;
      } else { // nums[i] == nums[i-1]
	up[i] = up[i-1];
	down[i] = down[i-1];
      }
    
    return max( up[n-1], down[n-1] );
}

// We only need to store 2 states up and down.

int wiggleMaxLength( vector<int>& nums ) {
  int n = nums.size();
  if( n == 0 ) return 0;

  int up = 1, down = 1;
  for( int i=1; i < n; i++ )
    if( nums[i] > nums[i-1] )
      up = down + 1;
    else if( nums[i] < nums[i-1] )
      down = up + 1;

  return max( up, down );
}
