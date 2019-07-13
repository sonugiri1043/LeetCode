/*
  42. Trapping Rain Water
  
  https://leetcode.com/problems/trapping-rain-water/

  Given n non-negative integers representing an elevation map where the width of each bar is 1,
  compute how much water it is able to trap after raining.

  Example:
  Input: [0,1,0,2,1,0,1,3,2,1,2,1]
  Output: 6
 */

class Solution {
public:
  int trap(vector<int>& height) {
    vector<int> maxFromLeft( height.size(), 0 );
    vector<int> maxFromRight( height.size(), 0 );
        
    int max = 0;
    for( int i=0; i < height.size(); i++ ) {
      if( height[i] > max ) {
	max = height[i];
      }
      maxFromLeft[i] = max;
    }
    max = 0;
    for( int i = height.size() - 1; i >= 0; i-- ) {
      if( height[i] > max ) {
	max = height[i];
      }
      maxFromRight[i] = max;
    }
    int totalWater = 0;
    for(int i=0; i < height.size(); i++  ) {
      totalWater += min( maxFromLeft[i], maxFromRight[i]) - height[i];
    }
    return totalWater;
  }
};
