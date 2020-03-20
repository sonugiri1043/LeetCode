/*
  698. Partition to K Equal Sum Subsets
  Given an array of integers nums and a positive integer k,
  find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

  Example 1:

  Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
  Output: True
  Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
 */

class Solution {
public:
  bool canPartitionKSubsets( vector<int>& nums, int k ) {
    int sum = 0, maxNo=nums[0];
    for( auto num : nums ) {
      sum += num;
      maxNo = max( num, maxNo );
    }
    int targetSum = sum/k;
    if( sum % k != 0 || maxNo > targetSum ) return false;

    vector<bool> visited( nums.size(), false );
    return partitionHelper( k, nums, visited, targetSum, 0, 0 );
  }
    
  bool partitionHelper( int remPartition, vector<int>& nums,
			vector<bool>& visited, int targetSum,
			int currSum, int index ) {
    if( remPartition == 1 ) return true;
    if( currSum == targetSum ) {
      return partitionHelper( remPartition-1, nums, visited, targetSum, 0, 0 );
    }
    for( int i=index; i < nums.size(); i++ ) {
      if( !visited[i] && currSum + nums[i] <= targetSum ) {
	visited[i] = true;
	if( partitionHelper( remPartition, nums, visited, targetSum, currSum + nums[i], i + 1 ) ) {
	  return true;
	}
	visited[i] = false;
      }
    }
    return false;
  }
};

