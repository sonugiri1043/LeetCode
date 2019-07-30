/*
  34. Find First and Last Position of Element in Sorted Array

  Given an array of integers nums sorted in ascending order, find the starting
  and ending position of a given target value.

  Your algorithm's runtime complexity must be in the order of O(log n).
  
  If the target is not found in the array, return [-1, -1].

  Example 1:
  Input: nums = [5,7,7,8,8,10], target = 8
  Output: [3,4]

  Example 2:
  Input: nums = [5,7,7,8,8,10], target = 6
  Output: [-1,-1]
 */

class Solution {
  vector<int> getPos( vector<int> nums, int index, int target ) {
    int start = index;
    while( start >= 0 && nums[start] == target )
      --start;
    int end = index;
    while( end <= ( nums.size() - 1 ) && nums[end] == target )
      ++end;
    return { start + 1, end -1 };
  }
    
public:
  vector<int> searchRange( vector<int>& nums, int target ) {
    int start = 0;
    int end = nums.size() - 1;
    int mid;
    while( start <= end ) {
      mid = ( start + end )/2;
      if( nums[ mid ] == target )
	return getPos( nums, mid, target );
      else if( nums[ mid ] > target )
	end = mid - 1;
      else 
	start = mid + 1;
    }
    return { -1, -1 };
  }
};
