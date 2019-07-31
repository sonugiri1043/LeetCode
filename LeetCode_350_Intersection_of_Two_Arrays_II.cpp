/*
  350. Intersection of Two Arrays II

  Given two arrays, write a function to compute their intersection.

  Example 1:
  Input: nums1 = [1,2,2,1], nums2 = [2,2]
  Output: [2,2]

  Example 2:
  Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
  Output: [4,9]

  Note:
  Each element in the result should appear as many times as it shows in both arrays.
  The result can be in any order.
 */

class Solution {
public:
  vector<int> intersect( vector<int>& nums1, vector<int>& nums2 ) {
    unordered_map<int, int > nums1Freq;
    vector<int> result;   
    for( auto n : nums1 ) {
      if( nums1Freq.count(n) )
	nums1Freq[n] += 1;
      else
	nums1Freq[n] = 1;
    }
    for( auto n : nums2 ) {
      if( nums1Freq.find(n) != nums1Freq.end() ) {
	if( nums1Freq[n] > 0 ) {
	  result.push_back( n );
	  nums1Freq[n]--;
	}
      }
    }
    return result;
  }
};
