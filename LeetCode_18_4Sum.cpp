/*
  Given an array nums of n integers and an integer target, are there
  elements a, b, c, and d in nums such that a + b + c + d = target?
  Find all unique quadruplets in the array which gives the sum of target.

  Note:
  The solution set must not contain duplicate quadruplets.

  Example:
  Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
  A solution set is:
  [
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
  ]
 */

class Solution {
public:
  vector<vector<int>> fourSum( vector<int>& nums, int target ) {
    vector<vector<int>> result;
    size_t n = nums.size();
    if( n < 4 ) return result;     
    sort( nums.begin(), nums.end() );
    for( int i=0; i < n-3; ++i ) {
      if( i > 0 && nums[i] == nums[i-1] ) continue; // avoid duplicates
      if( nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target ) break;
      if( nums[i] + nums[n-3] + nums[n-2] + nums[n-1 ] < target ) continue;
      for( int j=i+1 ; j < n-2; ++j ) {
	if( j > i+1 && nums[j] == nums[j-1] ) continue; // avoid duplicates
	if( nums[i] + nums[j] + nums[j+1] + nums[j+2] > target ) break;
	if( nums[i] + nums[j] + nums[n-2] + nums[n-1] < target ) continue;
	int l = j+1; // left pointer
	int r = n-1; // right pointer
	while( l < r ) {
	  int sum = nums[i] + nums[j] + nums[l] + nums[r];
	  if( sum < target ) {
	    ++l; // increment left pointer since sum < target
	  } else if( sum > target ) {
	    --r; // decrement right pointer since sum > target
	  } else {
	    result.push_back( { nums[i], nums[j], nums[l], nums[r] } );
	    // avoid duplicates
	    do { l++; } while( nums[l] == nums[l-1] && l < r );
	    do { r--; } while( nums[r] == nums[r+1] && l < r );
	  }
	}
      }
    }
    return result;
  }
};
