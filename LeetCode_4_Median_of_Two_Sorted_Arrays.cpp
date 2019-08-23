/*
  4. Median of Two Sorted Arrays
  There are two sorted arrays nums1 and nums2 of size m and n respectively.
  Find the median of the two sorted arrays. The overall run time complexity
  should be O(log (m+n)).

  You may assume nums1 and nums2 cannot be both empty.
  Example 1:
  nums1 = [1, 3]
  nums2 = [2]
  The median is 2.0

  Example 2:
  nums1 = [1, 2]
  nums2 = [3, 4]
  The median is (2 + 3)/2 = 2.5
*/

class Solution {
public:
  double findMedianSortedArrays( vector<int>& nums1, vector<int>& nums2 ) {
    int m=nums1.size(), n=nums2.size();
    if( m > n )  return findMedianSortedArrays( nums2, nums1 );

    int half = ( m+n+1 )/2; /* half of total number of elements */
    int ilow = 0, ihigh = m; /* binary search index range in nums1 */
    int i, j; /* Elements to the left and right of i and j partitions
		 nums1 and nums2 to equal halfs */

    while( ilow <= ihigh ) {
      i = ( ilow + ihigh )/2;
      j = half - i;
      if( i > 0 && nums1[i-1] > nums2[j] ) {
	ihigh = i - 1; /* i needs to be decreases */
      } else if ( i < m && nums1[i] < nums2[j-1] ) {
	ilow = i + 1; /* i needs to be increased */
      } else {
	/* all element to left of i & j <= all element to right of i&j */
	break;
      }
    }
        
    int leftMax, rightMin;
    if( i == 0 ) leftMax = nums2[j-1];
    else if( j == 0 ) leftMax = nums1[i-1];
    else leftMax = max( nums1[i-1], nums2[j-1] ); 
        
    if( ( m+n) % 2 == 1 ) return leftMax;
        
    if( i == m ) rightMin = nums2[j];
    else if( j == n ) rightMin = nums1[i];
    else rightMin = min( nums1[i], nums2[j] ); 
    return (leftMax + rightMin)/2.0;
  }
};
