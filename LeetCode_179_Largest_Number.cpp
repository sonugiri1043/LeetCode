/*
  179. Largest Number
  
  Given a list of non negative integers, arrange them such that they form the largest number.

  Example 1:
  Input: [10,2]
  Output: "210"

  Example 2:
  Input: [3,30,34,5,9]
  Output: "9534330"
  Note: The result may be very large, so you need to return a string instead of an integer.
 */

class Solution {
  static bool compareInts( int a, int b ) {
    string A = to_string( a );
    string B = to_string( b );
    long ab = stol( A + B );
    long ba = stol( B + A );
    return ab > ba;
  }

public:
  string largestNumber( vector<int>& nums ) {
    if( nums.size() == 0 ) return "";
    // sort the numbers accroding to compareInts fn
    sort( nums.begin(), nums.end(), compareInts );
    // if the heighest number is 0 then return 0
    if( nums[0]  == 0 ) return "0";
        
    string result = "";
    for( auto n : nums )
      result += to_string( n );
        
    return result;
  }
};
