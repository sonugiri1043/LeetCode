/*
  Given a collection of numbers that might contain duplicates,
  return all possible unique permutations.

  Example:
  Input: [1,1,2]
  Output:
  [
  [1,1,2],
  [1,2,1],
  [2,1,1]
  ]
*/

class Solution {
public:
  void permute( vector<int> nums, int start, vector<vector<int>> &result) {
    if( start == nums.size() - 1 ) {
      result.push_back( nums );
      return;
    }
    for( int i = start; i < nums.size(); i++ ) {
      if( start != i && nums[start] == nums[i] ) continue;       
      swap( nums[start], nums[i] );
      permute( nums, start + 1, result );
    }
  }
    
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    permute( nums, 0, result);
    return result;
  }
};
