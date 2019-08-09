/*
  15. 3Sum
  Given an array nums of n integers, are there elements a, b, c in nums
  such that a + b + c = 0? Find all unique triplets in the array which
  gives the sum of zero.

  Note:
  The solution set must not contain duplicate triplets.

  Example:
  Given array nums = [-1, 0, 1, 2, -1, -4],
  A solution set is:
  [
  [-1, 0, 1],
  [-1, -1, 2]
  ]
 */

class Solution {
public:
  vector<vector<int>> threeSum( vector<int>& nums ) {
    sort( nums.begin(), nums.end() );
        
    set< vector<int> > result;
    int l, r, sum;
    size_t size = nums.size();
    for( int i=0; i<size; ++i ) {
      if( nums[i] <= 0 ) {
	l = i + 1;
	r = size - 1;
	while( l < r ) {
	  sum = nums[l] + nums[r] + nums[i];
	  if( sum == 0 ) {
	    result.insert( { nums[i], nums[l], nums[r] } );
	    l++;
	    r--;
	  } else if( sum < 0 ) {
	    l++;
	  } else {
	    r--;
	  }
	}
      }
    }
    vector<vector<int>> arr;
    for( auto res : result ) arr.push_back( res );
    return arr;
  }
};
