/*
  https://leetcode.com/problems/first-missing-positive/
  
  41. First Missing Positive
  Given an unsorted integer array, find the smallest missing positive integer.

  Example 1:
  Input: [1,2,0]
  Output: 3

  Example 2:
  Input: [3,4,-1,1]
  Output: 2
*/

class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    // store all +ve no's in map the check for no's from 1 to max
    unordered_map<int, bool> nos;
    int max = 0;
    for( int i=0; i< nums.size(); i++ ) {
      if( nums[i] > 0 ) {
	nos[ nums[i] ] = true;
      }
      if( nums[i] > max ) {
	max = nums[i];
      }
    }
  
    int i = 1;
    while( i <= max ) {
      if( nos.find(i) == nos.end() ) {
	return i;
      }
      i++;
    }
    return max+1;
  }
};
