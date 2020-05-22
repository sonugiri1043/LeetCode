/*
  Longest Continuous Increasing Subsequence [LeetCode 674]
  Given an unsorted array of integers, find the length of longest continuous
  increasing subsequence (subarray).
  
  Example:
  Input: [1,3,5,4,7]
  Output: 3
  Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
  Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where
  5 and 7 are separated by 4. 

  Input: [2,2,2,2,2]
  Output: 1
  Explanation: The longest continuous increasing subsequence is [2], its length is 1.
*/

/*
  A continuous subsequence is essentially a subarray. Hence this question is asking for
  the longest increasing subarray and I have no idea why the question calls it a continuous
  subsequence to confuse the readers.
*/

int findLengthOfLCIS( vector<int>& nums ) {
  int n = nums.size();
  if( n == 0 ) return 0;
  
  vector<int> dp( n, 0 );
  dp[0] = 1;
  
  int longest = 1;
  for( int i=1; i < n; i++ ) {
    if( nums[i] > nums[i-1] )
      dp[i] = dp[i-1] + 1;
    else
      dp[i] = 1;
    longest = max( longest, dp[i] );
  }
  return longest;
}

// This can be further improved to use O(1) space. The else block can also be avoided.


