/*
  https://leetcode.com/problems/contains-duplicate/

  217. Contains Duplicate
  Given an array of integers, find if the array contains any duplicates.
  Your function should return true if any value appears at least twice in the array,
  and it should return false if every element is distinct.

  Example 1:
  Input: [1,2,3,1]
  Output: true

  Example 2:
  Input: [1,2,3,4]
  Output: false
*/

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    set<int> noDup;
    for( auto n : nums ) {
      if( noDup.count( n ) ) return true;
      noDup.insert( n );
    }
    return false;
  }
};
