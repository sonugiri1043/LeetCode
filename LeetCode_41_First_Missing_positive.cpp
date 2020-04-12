/*
  https://leetcode.com/problems/first-missing-positive/
  
  41. First Missing Positive
  Given an unsorted integer array, find the smallest missing positive integer.

  Example 1:
  Input: [1,2,0]
  Output: 3

  Example 2:
  Input: [3,4,-1,1]
  Output: 2
*/

class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    // store all +ve no's in map the check for no's from 1 to max
    unordered_map<int, bool> nos;
    int max = 0;
    for( int i=0; i< nums.size(); i++ ) {
      if( nums[i] > 0 ) {
	nos[ nums[i] ] = true;
      }
      if( nums[i] > max ) {
	max = nums[i];
      }
    }
  
    int i = 1;
    while( i <= max ) {
      if( nos.find(i) == nos.end() ) {
	return i;
      }
      i++;
    }
    return max+1;
  }
};

int firstMissingPositive( vector<int>& nums ) {
  int n = nums.size();
  // Assume range = 1..n
  // 1. Mark numbers outside range with a special marker number ( n+1 ) 
  // ( we can ignore those outside range because even if one number
  // is outside range then we will have one +ve missing within range.
  for( int i=0; i<n; i++ ) {
    if( nums[i] <= 0 || nums[i] > n ) 
      nums[i] = n + 1;
  }
  // note: all number in the array are now positive, and on the range 1..n+1
        
  // 2. mark each cell appearing in the array, by converting the index for that number to negative
  for( int i=0; i< n; i++ ) {
    int no = abs( nums[i] );
    if( no == n+1 ) continue;
    if( nums[ no - 1 ] > 0 ) { // prevent double -ve operations
      nums[ no - 1 ] *= -1;
    }
  }
        
  // 3. find the first cell which isn't negative (doesn't appear in the array)
  for( int i=0; i < n; i++ ) {
    if( nums[i] > 0 ) return i+1;
  }
        
  // 4. no positive numbers were found, which means the array contains all numbers 1...n
  return n+1;
}
};
