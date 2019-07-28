/*
  80. Remove Duplicate from Sorted Array II
  Given a sorted array nums, remove the duplicates in-place such that duplicates
  appeared at most twice and return the new length.

  Do not allocate extra space for another array, you must do this by modifying the
  input array in-place with O(1) extra memory.

  Example 1:
  Given nums = [1,1,1,2,2,3],
  Your function should return length = 5, with the first five elements of nums being
  1, 1, 2, 2 and 3 respectively.
  It doesn't matter what you leave beyond the returned length.

  Example 2:
  Given nums = [0,0,1,1,1,1,2,3,3],
  Your function should return length = 7, with the first seven elements of nums being
  modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

  It doesn't matter what values are set beyond the returned length.
 */

class Solution {
public:
  int removeDuplicates( vector<int>& nums ) {
    int start = -1; // all the elements till this index have count <= 2
    int count = 0;
    int i = 0;
    int j, tmp;
    while( i < nums.size() ) {
      tmp = nums[i];
      j = i;
      // count the element at index i
      count = 0;
      while( j < nums.size() && nums[j] == tmp ) {
	count++;
	j++;
      }
            
      // increment i by count to check for next element
      i = i + count;
            
      // update the array in-place
      count = min( count, 2 );
      while( count ) {
	nums[++start] = tmp;
	--count;
      }       
    }
    return start + 1;
  }
};
