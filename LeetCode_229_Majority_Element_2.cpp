/*
  https://leetcode.com/problems/majority-element-ii/

  229. Majority Element II

  Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

  Note: The algorithm should run in linear time and in O(1) space.

  Example 1:
  Input: [3,2,3]
  Output: [3]

  Example 2:
  Input: [1,1,1,3,3,2,2,2]
  Output: [1,2]
 */

class Solution {
public:
  vector<int> majorityElement( vector<int>& nums ) {
    // since we are looking for majority with more than n/3 votes
    // we can have only two majority element at max.
        
    // use moore's voting algorithm to get suspected majority1 and majority2
    int majority1 = INT_MAX, majority2 = INT_MAX;
    int votes1 = 0, votes2 = 0;
    for( auto num : nums ) {
      if( num == majority1 ) {
	votes1++;
      } else if ( num == majority2 ) {
	votes2++;
      } else if( votes1 == 0 ) {
	majority1 = num;
	votes1 = 1;
      } else if( votes2 == 0 ) {
	majority2 = num;
	votes2 = 1;
      } else {
	votes1--;
	votes2--;
      }
    }
        
    // get the actual count of majority1 and majority2
    votes1 = 0, votes2 = 0;
    for( auto num : nums ) {
      if( num == majority1 )  { 
	votes1++; 
                
      } else if( num == majority2 ) {
	votes2++;
      }
    }

    // verify count
    vector<int> res;
    if( votes1 > nums.size()/3.0 ) res.push_back( majority1 );
    if( votes2 > nums.size()/3.0 ) res.push_back( majority2 );
    return res;
  }
};
