/*
  448. Find All Numbers Disappeared in an Array

  Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array),
  some elements appear twice and others appear once.
  Find all the elements of [1, n] inclusive that do not appear in this array.

  Could you do it without extra space and in O(n) runtime? You may assume
  the returned list does not count as extra space.

  Example:
  Input:
  [4,3,2,7,8,2,3,1]
  Output:
  [5,6]
*/

/*
Scan array from left to right:

For number n at index i mark nums[n - 1] as -ve iff nums[n - 1] > 0.
Again scan the array:
If num[ index ] > 0 means index + 1 is missing otherwise this element would have been set to -ve.  */

class Solution {
public:
  vector<int> findDisappearedNumbers( vector<int>& nums ) {
    vector<int> result;
    for( int i=0; i < nums.size(); i++ ) {
      if( nums[abs(nums[i])-1] > 0 ) {
	nums[abs(nums[i])-1] *= -1;
      }
    }
    for( int i=0; i < nums.size(); i++ ) {
      if( nums[i] > 0 )
	result.push_back( i + 1 );
    }
    return result;
  }
};
