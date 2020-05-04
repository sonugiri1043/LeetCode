/*
  154. Find Minimum in Rotated Sorted Array II
  Suppose an array sorted in ascending order is rotated at some
  pivot unknown to you beforehand.

  (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
  Find the minimum element.
  The array may contain duplicates.

  Example 1:
  Input: [1,3,5]
  Output: 1
  Example 2:
  Input: [2,2,2,0,1]
  Output: 0

https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/discuss/613620/C%2B%2B-O(log-N)-or-O(N)-worst-case-or-Explained-with-Diagram
 */

int findMin(vector<int>& nums) {
  int l = 0, r = nums.size() - 1;
  while( l < r ) {
    int m = l + (r - l) / 2;
    if( nums[m] > nums[r] ) {
      l = m + 1;
    } else if( nums[m] < nums[r] ) {
      r = m;
    } else {
      r--;
    }
  }
  return nums[l];
}
