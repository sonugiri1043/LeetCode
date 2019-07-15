/*
  Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

  Note:
  The number of elements initialized in nums1 and nums2 are m and n respectively.
  You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold
  additional elements from nums2.

  Example:
  Input:
  nums1 = [1,2,3,0,0,0], m = 3
  nums2 = [2,5,6],       n = 3

  Output: [1,2,2,3,5,6]
 */

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    class Solution {
    public:
      void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m-1;
        int q = n-1;
        int i = m + n -1;
        // copy elements in nums1 starting from the largest element
        for( i = m + n - 1; i >= 0; --i ) {
	  if( p == -1 || q == -1 ) {
	    break;
	  }
	  if( nums1[p] < nums2[q] ) {
	    nums1[i] = nums2[q];
	    q--;
	  } else {
	    nums1[i] = nums1[p];
	    p--;
	  }
        }
        
        // check one of array is done and other is remaining
        if( p > 0 ) {
	  while( i >= 0 ) {
	    nums1[i] = nums1[p];
	    i--;
	    p--;
	  }
        }
        if ( q >= 0 ) {
	  while( i >= 0 ) {
	    nums1[i] = nums2[q];
	    i--;
	    q--;
	  }
        }
      }
    };
  }
};
