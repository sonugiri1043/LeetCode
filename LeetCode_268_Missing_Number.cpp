/*
  https://leetcode.com/problems/missing-number/

  268. Missing Number
  Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the
  one that is missing from the array.

  Example 1:
  
  Input: [3,0,1]
  Output: 2
*/

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    vector<bool> present( nums.size() + 1, true );
    for( int i=0; i < nums.size(); i++ ) {
      present[ nums[i] ] = false;
    }
    for( int i=0; i <= nums.size(); i++ ) {
      if( present[i] ) {
	return i;
      }
    }
    return -1;
  }
};
