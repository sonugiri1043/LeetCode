/*
  765. Couples Holding Hands
  N couples sit in 2N seats arranged in a row and want to hold hands.
  We want to know the minimum number of swaps so that every couple is
  sitting side by side. A swap consists of choosing any two people, then
  they stand up and switch seats.

  The people and seats are represented by an integer from 0 to 2N-1,
  the couples are numbered in order, the first couple being (0, 1),
  the second couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).

  The couples' initial seating is given by row[i] being the value of the person
  who is initially sitting in the i-th seat.

  Example 1:
  Input: row = [0, 2, 1, 3]
  Output: 1
  Explanation: We only need to swap the second (row[1]) and third (row[2]) person.

  Example 2:
  Input: row = [3, 2, 0, 1]
  Output: 0
  Explanation: All couples are already seated side by side
 */


/* 
    Think about each couple as a vertex in the graph. So if there are N couples,
    there are N vertices.
    
    The min number of swaps = N - number of connected components. This follows
    directly from the theory of permutations. Any permutation can be decomposed
    into a composition of cyclic permutations. If the cyclic permutation involve
    k elements, we need k -1 swaps. You can think about each swap as reducing the
    size of the cyclic permutation by 1. So in the end, if the graph has k connected
    components, we need N - k swaps to reduce it back to N disjoint vertices.
*/
class Solution {
  int find( vector<int> &groups, int i ) {
    while( i != groups[i] )
      i = groups[i];
    return i;
  }
    
public:
  int minSwapsCouples( vector<int>& row ) {
    /* Initialize n groups one for each couple */
    int n = row.size()/2;
    vector<int> groups(n);
    for( int i=0; i<n; i++ )
      groups[i] = i;
        
    /* Try to map couple at index i to group i/2. If one spouse is already
       mapped then merge groups */
    unordered_map<int, int> coupleToGroup;
    for( int i=0; i<row.size(); i++ ) {
      int couple = row[i]/2;
      if( coupleToGroup.find( couple ) == coupleToGroup.end() )
	coupleToGroup[couple] = i/2;
      else {
	// Union
	int root1 = find( groups, coupleToGroup[couple] );
	int root2 = find( groups, i/2 );
	groups[root1] = root2;
      }
    }
        
    /* count no of connected component */
    int connectedComp = 0;
    for( int i=0; i < n; i++ ) 
      if( groups[i] == i ) connectedComp++;
        
    return n - connectedComp;
  }
};
