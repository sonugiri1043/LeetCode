/*
Partition Equal Subset Sum [LeetCode 416][LinkedIn]*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
Note:
Each of the array elements will not exceed 100.
The array size will not exceed 200.

Input: [1, 5, 11, 5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Input: [1, 2, 3, 5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
*/

/*
0 / 1 Knapsack
Actually, this is a 0/1 knapsack problem, for each number, we can pick it or not.
Let us assume dp[i][j] means whether the specific sum j can be gotten from the first i numbers.
*/

bool canPartition( vector<int>& nums ) {
  int n = nums.size();
  int sum = 0;
  for( auto num : nums ) sum += num;
  
  if( sum % 2 == 1 ) return false;
  
  vector<vector<int>> dp( n+1, vector<int>( sum/2 + 1, 0 ) );
  for( int i=1; i <= n; i++ ) // items
    for( int j=1; j <= sum/2; j++ ) // weights => possible sum 
      if( nums[i-1] > j ) // can't pick this number
	dp[i][j] = dp[i-1][j];
      else
	dp[i][j] = max( dp[i-1][j], nums[i-1]+dp[i-1][j-nums[i-1]]);
  
  for( int i=1; i <= n; i++ )
    if( dp[i][sum/2] == sum/2 )
      return true;
  return false;   
}

// Using Backtracking
class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(int i =0;i<nums.size();i++){
      sum+= nums[i];
    }
    if(sum%2) return false;
    sum /= 2;
    sort( nums.rbegin(),nums.rend() );
    return helper( nums, sum, 0 );
  }
  bool helper(vector<int>& nums, int sum, int index){
    if(sum == nums[index]) return true;
    if(sum < nums[index]) return false;
    return helper(nums,sum-nums[index],index+1) || helper(nums,sum,index+1);
  }
};
