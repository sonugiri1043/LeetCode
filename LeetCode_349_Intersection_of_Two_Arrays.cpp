/*
  349. Intersection of Two Arrays

  Given two arrays, write a function to compute their intersection.
  Example 1:
  Input: nums1 = [1,2,2,1], nums2 = [2,2]
  Output: [2]

  Example 2:
  Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
  Output: [9,4]

  Note:
  Each element in the result must be unique.
  The result can be in any order
 */

class Solution {
public:
  vector<int> intersection( vector<int>& nums1, vector<int>& nums2 ) {
    if( nums1.size() > nums2.size() ) return intersection( nums2, nums1 );
        
    vector<int> result;
    set<int> nums1Set;
    for( auto n : nums1 )
      nums1Set.insert( n );
        
    for( auto n : nums2 ) {
      if( nums1Set.count(n) ) {
	result.push_back( n );
	nums1Set.erase(n);
      }
    }
    return result;
  }
};
