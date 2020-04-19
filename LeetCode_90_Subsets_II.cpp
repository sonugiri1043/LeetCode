/*
  Subsets With Duplicate numbers [LeetCode 90]
  Given a collection of integers that might contain duplicates, nums, return
  all possible subsets (the power set). 

  Note: The solution set must not contain duplicate subsets.
 */

// Note: 1.sort. 2. copy the subsets only if there are no dups.
vector<vector<int>> subsetsWithDup( vector<int>& nums ) {
  sort( nums.begin(), nums.end() );
        
  vector<vector<int>> subsets, tmpSubs;
  subsets.push_back({});
  for( int i=0; i < nums.size(); i++ ) {
    if( i==0 || nums[i-1] != nums[i] ) tmpSubs = subsets;
    for( int j=0; j < tmpSubs.size(); j++ ) {
      tmpSubs[j].push_back( nums[i] );
    }
    subsets.insert(subsets.end(),tmpSubs.begin(), tmpSubs.end());
  }
  return subsets;
}
