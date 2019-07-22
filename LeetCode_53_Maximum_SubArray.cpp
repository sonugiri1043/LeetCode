/*
  https://leetcode.com/problems/maximum-subarray/

  53. Maximum Subarray
  Given an integer array nums, find the contiguous subarray
  (containing at least one number) which has the largest sum and return its sum.

  Example:
  Input: [-2,1,-3,4,-1,2,1,-5,4],
  Output: 6
  Explanation: [4,-1,2,1] has the largest sum = 6.
 */

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int localSum = nums[0];
    int globalSum = localSum;
    for( int i=1; i < nums.size(); i++ ) {
      localSum = max( nums[i], nums[i] + localSum );
      if( localSum > globalSum )
	globalSum = localSum;
    }
    return globalSum;
  }
};
