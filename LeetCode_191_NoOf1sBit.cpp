/*
  https://leetcode.com/problems/number-of-1-bits/
  191. Number of 1 Bits

  Write a function that takes an unsigned integer and return the number of '1' bits
  it has (also known as the Hamming weight).

  Example 1:
  
  Input: 00000000000000000000000000001011
  Output: 3
  Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
 */

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int noOf1s = 0;
    while( n ) {
      if( n & 1 ) {
	noOf1s++;
      }
      n = n >> 1;
    }
    return noOf1s;
  }
};
