/*
Counting Bits [LeetCode 338]
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
Example:
Input: 2
Output: [0,1,1]
Input: 5
Output: [0,1,1,2,1,2]
*/

/*
Number of 1 bits in a even number 'N' is same as 'N' >> 1 that is N/2.
Number of 1 bits in off number 'N' is 'N' >> 1 + 1 that is N/2 + 1
*/
vector<int> countBits(int num) {
  vector<int> result( num + 1, 0 );
 for( int i=1; i <= num; i++ ) {
   if( i % 2 )
     result[i] = result[i>>1] + 1;
   else
     result[i] = result[i>>1];
 }
 return result;
}
