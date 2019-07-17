// Approach 1:

class Solution {
public:
  void getPermutations( vector<int>& nums, vector<vector<int>> &permutations,
			vector<int> &perm ) {
    if( perm.size() == nums.size() ) {
      permutations.push_back( perm );
      return;
    }
    int tmp;
    for( int i=0; i < size; i++ ) {
      if( nums[ i ] == INT_MIN ) continue;
      perm.push_back( nums[i] );
      tmp = nums[i];
      nums[i] = INT_MIN;
      getPermutations( nums, permutations, perm, size );
      nums[i] = tmp;
      perm.pop_back();
    }
  }
    
  vector<vector<int>> permute( vector<int>& nums ) {
    vector< vector<int> > permutations;
    vector<int> perm;
    getPermutations( nums, permutations, perm );
    return permutations;
  }
};

// Approach 2
class Solution {
public:
  void getPermutations( vector<int>& nums, vector<vector<int>> &permutations,
			int left, int right ) {
    if( left >= right ) {
      permutations.push_back( nums );
      return;
    }
    for( int i = left; i < right; i++ ) {
      swap( nums[ left ], nums[i] );
      getPermutations( nums, permutations, left + 1, right );

      // reset
      swap( nums[ left ], nums[i] );
    }
  }
    
  vector<vector<int>> permute( vector<int>& nums ) {
    vector< vector<int> > permutations;
    getPermutations( nums, permutations, 0, nums.size() );
    return permutations;
  }
};

