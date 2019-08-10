/*
  238. Product of Array Except Self
  Given an array nums of n integers where n > 1,  return an array output
  such that output[i] is equal to the product of all the elements of nums
  except nums[i].

  Example:
  Input:  [1,2,3,4]
  Output: [24,12,8,6]
  Note: Please solve it without division and in O(n).
 */

class Solution {
public:
  vector<int> productExceptSelf( vector<int>& nums ) {
    size_t n = nums.size();
    vector<int> result( n, 1 );
    vector<int> high( n, 1 );
    for( int i=1; i < n; ++i ) {
      result[i] = result[i-1]*nums[i-1];
    }
    for( int i=n-2; i >= 0; --i ) {
      high[i] = high[i+1]*nums[i+1];
    }
    for( int i=0; i < n; ++i ) {
      result[i] = result[i]*high[i];
    }
    return result;
  }
};


class Solution {
public:
  vector<int> productExceptSelf( vector<int>& nums ) {
    size_t n = nums.size();
    vector<int> result( n, 1 );
    for( int i=1; i < n; ++i ) {
      // get the product from start
      result[i] = result[i-1]*nums[i-1];
    }
    int productFromLast = 1;
    for( int i=n-1; i >= 0; --i ) {
      result[i] = result[i]*productFromLast;
      // get product from end on the go.
      productFromLast = productFromLast * nums[i];
    }
    return result;
  }
};
