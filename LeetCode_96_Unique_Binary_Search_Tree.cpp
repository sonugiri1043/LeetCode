/*
  96. Unique Binary Search Trees
  Given n, how many structurally unique BST's (binary search trees) that
  store values 1 ... n?

  Example:
  Input: 3
  Output: 5
  Explanation:
  Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

/*  
  Consider each node from 1 to n as root once:

  when 1 as root: # of trees = F(0) * F(n-1)  // F(0) == 1
  when 2 as root: # of trees = F(1) * F(n-2) 
  when 3 as root: # of trees = F(2) * F(n-3)
  ...
  when n-1 as root: # of trees = F(n-2) * F(1)
  when n as root:   # of trees = F(n-1) * F(0)
  So, the formulation is:
  F(n) = F(0) * F(n-1) + F(1) * F(n-2) + F(2) * F(n-3) + ... + F(n-2) * F(1) + F(n-1) * F(0)
*/
class Solution {
public:
  int numTrees( int n ) {
    vector<int> noOfTree( n+1, 0 );
    noOfTree[0] = 1;
    noOfTree[1] = 1;
    for( int i=2; i <= n; ++i ) {
      for( int j=0; j < i; j++ ) {
	noOfTree[i] += noOfTree[j] * noOfTree[i-1-j];
      }
    }
    return noOfTree[n];
  }
};
