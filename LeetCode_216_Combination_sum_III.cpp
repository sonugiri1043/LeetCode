/*
  216. Combination Sum III
  Find all possible combinations of k numbers that add up to a number n,
  given that only numbers from 1 to 9 can be used and each combination
  should be a unique set of numbers.

  Input: k = 3, n = 7
  Output: [[1,2,4]]

  Input: k = 3, n = 9
  Output: [[1,2,6], [1,3,5], [2,3,4]]
 */

class Solution {
public:
  vector<vector<int>> combinationSum3( int k, int n ) {   
    vector<vector<int>> result;
    vector<int> curr;
    backtrack( result, curr, n, 1, k );
    return result;
  }
  void backtrack(  vector<vector<int>>& result, vector<int>& curr, int need,
		   int start, int k ) {
    if( need < 0 ) return;
    if( need == 0 && k == 0 ) {
      result.push_back( curr );
      return;
    }
    for( int i=start; i <= 9 && i <= need; i++ ) {
      curr.push_back( i );
      backtrack( result, curr, need - i, i+1, k - 1 );
      curr.pop_back();
    }
  }
};
