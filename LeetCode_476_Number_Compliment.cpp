/*
  Number Complement [Leetcode 476]
  Given a positive integer, output its complement number. The complement strategy is to
  flip the bits of its binary representation.
  Example
  Input: 5
  Output: 2
  Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement
  is 010. So you need to output 2
  Input: 1
  Output: 0
  Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0.
  So you need to output 0.
 */

/*
num          = 00000110
mask         = 00000111
~num         = 11111001
mask & ~num  = 00000001
*/

int findComplement( int num ) {
  int mask = 0, tmp=num;
  while( tmp ) {
    tmp = tmp >> 1;
    mask = mask << 1;
    mask = mask | 1;
  }
  return ~num & mask;
}

