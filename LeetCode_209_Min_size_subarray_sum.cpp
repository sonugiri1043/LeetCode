/*
  209. Minimum Size Subarray Sum
  Given an array of n positive integers and a positive integer s,
  find the minimal length of a contiguous subarray of which the sum ≥ s.
  If there isn't one, return 0 instead.

  Example: 
  Input: s = 7, nums = [2,3,1,2,4,3]
  Output: 2
  Explanation: the subarray [4,3] has the minimal length under the problem constraint.
  Follow up:
 */

class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int windowStart = 0, windowSum = 0, minLen = INT_MAX;
    for( int windowEnd = 0; windowEnd < nums.size(); windowEnd++ ) {
      windowSum += nums[windowEnd];
      // shrink the window as small as possible until the 'windowSum' is greater than 's'
      while( windowSum >= s ) {
	minLen = min( minLen, windowEnd - windowStart + 1 );
	windowSum -= nums[windowStart]; // subtract the element going out
	windowStart++; // shrink the window
      }
    }
    return minLen == INT_MAX ? 0 : minLen;
  }
};
