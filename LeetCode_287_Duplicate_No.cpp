/*
  287. Find the Duplicate Number
  
  Given an array nums containing n + 1 integers where each integer is between 1 and n
  (inclusive), prove that at least one duplicate number must exist. Assume that there
  is only one duplicate number, find the duplicate one.

  Example 1:
  Input: [1,3,4,2,2]
  Output: 2
  Example 2:
 
  Input: [3,1,3,4,2]
  Output: 3

  Note:
  You must not modify the array (assume the array is read only).
  You must use only constant, O(1) extra space.
  Your runtime complexity should be less than O(n2).
  There is only one duplicate number in the array, but it could be repeated more than once.
*/

#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int>& nums) {
  int slow = nums[0];
  int fast = nums[ 0 ];

  do {
    slow = nums[ slow ];
    fast = nums[ nums[fast] ];
  } while( slow != fast );

  fast = nums[0];
  while( slow != fast ) {
    slow = nums[slow];
    fast = nums[fast];
  }

  return slow;
}

int main() {
  vector<int> arr = { 1, 3, 4, 2, 2 };
  vector<int> arr2 = { 3, 1, 3, 4, 2 };
  cout<< findDuplicate( arr ) << endl;
  cout<< findDuplicate( arr2 ) << endl;
  return 0;
}
