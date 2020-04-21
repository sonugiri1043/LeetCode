/*
  Given a collection of candidate numbers (candidates) and a target number
  (target), find all unique combinations in candidates where the candidate
  numbers sums to target.

  Each number in candidates may only be used once in the combination.
  Note:
  All numbers (including target) will be positive integers.
  The solution set must not contain duplicate combinations.

  Example 1:
  Input: candidates = [10,1,2,7,6,1,5], target = 8,
  A solution set is:
  [
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
  ]

  Example 2:
  Input: candidates = [2,5,2,1,2], target = 5,
  A solution set is:
  [
  [1,2,2],
  [5]
  ]
 */

class Solution {
public:
  vector<vector<int>> combinationSum2( vector<int>& candidates, int target ) {
    sort( candidates.begin(), candidates.end() );
        
    vector<vector<int>> result;
    vector<int> curr;
    backtrack( result, curr, 0, target, candidates );
    return result;
  }
private:
  void backtrack( vector<vector<int>>& result, vector<int>& curr, int start, int need,
		  vector<int>& cand ) {
    if( need == 0 ) {
      result.push_back( curr );
      return;
    }
    for( int i=start; i < cand.size() && need >= cand[i] ; i++ ) {
      if(i > start && cand[i] == cand[i-1]) continue; /** skip duplicates */
      curr.push_back( cand[i] );
      backtrack( result, curr, i+1, need - cand[i], cand );
      curr.pop_back();
    }
  }
};
