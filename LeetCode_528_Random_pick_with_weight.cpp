/*
  Random Pick with Weight [LeetCode 528]
  Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.
  Note:
  1 <= w.length <= 10000
  1 <= w[i] <= 10^5
  pickIndex will be called at most 10000 times.
  Example 1:
  Input: 
  ["Solution","pickIndex"]
  [[[1]],[]]
  Output: [null,0]
  
  Example 2:
  Input: 
  ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
  [[[1,3]],[],[],[],[],[]]
  Output: [null,0,1,1,1,0]
*/

class Solution {
  vector<int> sumOfWt; // sumOfWt[i] = sum of weights till index i
public:
  Solution( vector<int>& wts ) {
    for( auto wt : wts )
      if( sumOfWt.empty() )
	sumOfWt.push_back( wt );
      else
	sumOfWt.push_back( sumOfWt.back() + wt );
  }
  
  int pickIndex() {
    int totalSum = sumOfWt.back();
    int index = rand() % totalSum;
    auto it = upper_bound( sumOfWt.begin(), sumOfWt.end(), index );
    return it - sumOfWt.begin();
  }
};
