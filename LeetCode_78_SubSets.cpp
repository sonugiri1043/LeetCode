/*
  https://leetcode.com/problems/subsets/

  78. Subsets
  Given a set of distinct integers, nums, return all possible subsets (the power set).
  Note: The solution set must not contain duplicate subsets.

  Example:
  Input: nums = [1,2,3]
  Output:
  [
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
  ]
 */

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    /* use base and build approach with base case as empty set
           subset[ a1, a2, ... ai ] = subset[ a1, a2, ... a(i-1) ] + 
                                      ai appended to each subset
    */
    vector< vector<int> > allSubSets;
    vector< vector<int> > tmpSubSets;
    allSubSets.push_back( {} );
    for( auto n : nums ) {
      tmpSubSets = allSubSets;
      for( auto set : tmpSubSets ) {
	set.push_back(n);
	allSubSets.push_back( set );
      }
    }
    return allSubSets;
  }
};
