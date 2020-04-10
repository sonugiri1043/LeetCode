/*
  581. Shortest Unsorted Continuous Subarray

  Given an integer array, you need to find one continuous subarray that if you only
  sort this subarray in ascending order, then the whole array will be sorted in
  ascending order, too.

  You need to find the shortest such subarray and output its length.

  Example 1:
  Input: [2, 6, 4, 8, 10, 9, 15]
  Output: 5
  Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the
  whole array sorted in ascending order.
*/

class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    int left=INT_MAX, right=INT_MIN;
    int high = nums[0];
    for( int i=0; i < nums.size(); i++ ) {
      if( nums[i] >= high )
	high = nums[i];
      else {
	left = min( left, i );
	right = max( right, i );
      }
    }
        
    int low = nums[nums.size()-1];
    for( int i=nums.size()-1; i >= 0; i-- ) {
      if( nums[i] <= low ) {
	low = nums[i];
      } else {
	left = min( left, i);
	right = max( right, i );
      }
    }
    if( left == INT_MAX && right == INT_MIN ) return 0;
    return right - left + 1;    }
};
