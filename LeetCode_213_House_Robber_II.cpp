/*
  House Robber II [LeetCode 213]
  You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed.
  All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.
  Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two
  adjacent houses were broken into on the same night.
  Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount
  of money you can rob tonight without alerting the police.
*/

/*
 This problem is a little tricky at first glance.
 However, if you have finished the House Robber problem,
 this problem can simply be decomposed into two House Robber problems.
 Suppose there are n houses, since house 0 and n - 1 are now neighbors,
 we cannot rob them together and thus the solution is now the maximum of

 Rob houses 0 to n - 2;
 Rob houses 1 to n - 1.
 The code is as follows. Some edge cases (n < 2) are handled explicitly.
*/

class Solution {
public:
  int rob( vector<int>& nums ) {
    int n = nums.size(); 
    if( n < 2 ) return n ? nums[0] : 0;
    return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
  }
private:
  int robber( vector<int>& nums, int l, int r) {
    int pre = 0, cur = 0, next = 0;
    for( int i = l; i <= r; i++ ) {
      next = max(pre + nums[i], cur);
      pre = cur;
      cur = next;
    }
    return cur;
  }
};
