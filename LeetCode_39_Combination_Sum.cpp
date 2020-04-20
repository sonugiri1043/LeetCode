/*
  39. Combination Sum
  Given a set of candidate numbers (candidates) (without duplicates) and a target
  number (target), find all unique combinations in candidates where the candidate
  numbers sums to target.

  The same repeated number may be chosen from candidates unlimited number of times.
  Note:
  All numbers (including target) will be positive integers.
  The solution set must not contain duplicate combinations.

  Input: candidates = [2,3,6,7], target = 7,
  A solution set is:
  [
  [7],
  [2,2,3]
  ]
 */

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort( candidates.begin(), candidates.end() );
    vector<vector<int>> result;
    vector<int> curr;
    backtrack( result, candidates, curr, 0, target );
    return result;
  }
    
  void backtrack( vector<vector<int>> &result,vector<int>& candidates,
		  vector<int> &curr, int start, int need ) {
    if( 0 == need ) {
      result.push_back( curr );
    }
    for( int i=start; i < candidates.size() && need >= candidates[i]; i++ ) {
      curr.push_back( candidates[i] );
      // not i + 1 because we can reuse same elements
      backtrack( result, candidates, curr, i, need - candidates[i] ); 
      curr.pop_back();
    }
  }
};

