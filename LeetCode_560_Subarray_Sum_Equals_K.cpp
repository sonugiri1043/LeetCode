/*
  Subarray Sum Equals K [ LeetCode 560 ]
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Your input
[0,0,0,0,0,0,0,0,0,0]
0
Output
55
Expected
55
 */

// prefix Sum and hashmap
int subarraySum(vector<int>& nums, int k) {
  int windowStart = 0, sum = 0, result = 0;
  unordered_map<int, int> prefixSumMap;

  prefixSumMap[0] = 1;
  for( int i = 0; i < nums.size(); i++ ) {
    sum += nums[i];
    if( prefixSumMap.find( sum - k ) != prefixSumMap.end() )
      result += prefixSumMap[sum-k];
    prefixSumMap[ sum ]++;
  }
        
  return result;
}
