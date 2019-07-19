/*
  https://leetcode.com/problems/kth-largest-element-in-an-array/

  215. Kth Largest Element in an Array

  Find the kth largest element in an unsorted array.
  Note that it is the kth largest element in the sorted order, not the kth distinct element.

  Example 1:
  Input: [3,2,1,5,6,4] and k = 2
  Output: 5

  Example 2:
  Input: [3,2,3,1,2,4,5,5,6] and k = 4
  Output: 4

  Note: 
  You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

class Solution {
public:
  int findKth( vector<int> &nums, int left, int right, int k ) {
    if( left >= right ) {
      return nums[left];
    }
        
    // do partition around pivot
    int pivot = nums[left];
    int start = left - 1;
    int end = right + 1;
    for( int i=left; i < end; ) {
      if( nums[i] <= pivot ) {
	nums[++start] = nums[i];
	i++;
      } else {
	swap( nums[--end], nums[i] );
      }
    }
    swap( nums[left], nums[start] );
        
        
    if( k == start ) {
      return nums[k];
    } else if( k < start ) {
      return findKth( nums, left, start - 1, k );
    } else {
      return findKth( nums, start + 1, right, k );
    }
  }
    
  int findKthLargest(vector<int>& nums, int k) {       
    return findKth( nums, 0, nums.size() - 1, nums.size() - k );   
  }
};
