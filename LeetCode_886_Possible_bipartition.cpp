/*
  Possible Bipartition [LeetCode 886]
  Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
  Each person may dislike some other people, and they should not go into the same group. 
  Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
  Return true if and only if it is possible to split everyone into two groups in this way.

  Example:
  Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
  Output: true
  Explanation: group1 [1,4], group2 [2,3]
  
  Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
  Output: false
  
  Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
  Output: false
*/
class Solution {
  int find( vector<int> &parents, int i ) {
    if( i != parents[i] )
      i = parents[i];
      return i;
  }
public:
  bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    vector<int> parents(N);
    for( int i=0; i < N; i++ )
      parents[i] = i;
    
    unordered_map<int, vector<int>> adjList;
    for( auto dislike : dislikes ) {
      adjList[ dislike[0] - 1 ].push_back( dislike[1] - 1 );
      adjList[ dislike[1] - 1 ].push_back( dislike[0] - 1 );
    }
    
    for( auto adj : adjList ) {
      int root1 = find( parents, adj.first );
      for( auto nbr : adj.second ) {
	int root2 = find( parents, nbr );
	if( root1 == root2 )
	  return false;
	else
	  parents[root2] = adj.second[0];
      }
      }
    return true;
  }
};
