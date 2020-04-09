/*
  16. 3Sum Closest

  Given an array nums of n integers and an integer target, find three integers
  in nums such that the sum is closest to target. Return the sum of the three integers.
  You may assume that each input would have exactly one solution.

  Example:
  Given array nums = [-1, 2, 1, -4], and target = 1.
  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

class Solution {
public:
  int threeSumClosest( vector<int>& nums, int target ) {
    sort( nums.begin(), nums.end() );
    int left, right, sum, sum_diff = INT_MAX, closest;
    for( int i=0; i < nums.size() - 2; i++ ) {
      left = i + 1;
      right = nums.size() - 1;
      while( left < right ) {
	sum = nums[i] + nums[left] + nums[right];
	if( abs( sum - target ) < sum_diff ) {
	  closest = sum;
	  sum_diff = abs( sum - target );
	}
	if( sum > target ) {
	  right--;
	} else {
	  left++;
	}
      }
    }
    return closest;
  }
};
