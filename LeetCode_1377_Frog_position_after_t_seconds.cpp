/*
  Frog Position After T Seconds [LeetCode 1377] [Google]
  Given an undirected tree consisting of n vertices numbered from 1 to n.
  A frog starts jumping from the vertex 1. In one second, the frog jumps from
  its current vertex to another unvisited vertex if they are directly connected.
  The frog can not jump back to a visited vertex. In case the frog can jump to
  several vertices it jumps randomly to one of them with the same probability,
  otherwise, when the frog can not jump to any unvisited vertex it jumps forever
  on the same vertex. 
  
  The edges of the undirected tree are given in the array edges,
  where edges[i] = [fromi, toi] means that there exists an edge connecting
  directly the vertices fromi and toi.
  Return the probability that after t seconds the frog is on the vertex target
  
  Example 1:
  Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 2, target = 4
  Output: 0.16666666666666666 
  Explanation: The figure above shows the given graph. The frog starts at vertex 1,
  jumping with 1/3 probability to the vertex 2 after second 1 and then jumping with
  1/2 probability to vertex 4 after second 2. Thus the probability for the frog
  is on the vertex 4 after 2 seconds is 1/3 * 1/2 = 1/6 = 0.16666666666666666. 
  
  Example 2:
  Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 1, target = 7
  Output: 0.3333333333333333
  Explanation: The figure above shows the given graph. The frog starts at vertex 1,
  jumping with 1/3 = 0.3333333333333333 probability to the vertex 7 after second 1. 
  
  Example :
  Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 20, target = 6
  Output: 0.16666666666666666
*/

double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
  // Build adjacency matrix
  unordered_map<int, vector<int>> adjList;
  for( auto edge : edges ) {
    adjList[edge[0]].push_back( edge[1] );
    adjList[edge[1]].push_back( edge[0] );
  }
  
  // do BFS starting from node 1
  queue<int> q;
  set<int> visited;
  vector<float> prob( n+1, 0 );
  
  q.push( 1 );
  visited.insert( 1 );
  prob[1] = 1;
  
  while( !q.empty() && t-- > 0 ) {
    int size = q.size();
    for( int i=0; i < size; i++ ) {
      vector<int> child;
      int curr = q.front(); q.pop();
      for( auto nbr : adjList[ curr ] ) {
	if( visited.count( nbr ) == 0 ) {
	  visited.insert( nbr );
	  child.push_back( nbr );
	}
      }
      // transfer parent probability to children at t+1 time 
      for( int i = 0; i < child.size(); i++ ) {
	prob[ child[i] ] = prob[curr] / child.size();
	q.push( child[i] );
      }
      // frogs moves to children at t+1 so probability of parent becomes zero.
      if( child.size() != 0 )  prob[curr] = 0;
      child.clear();
    }
  }
  return prob[target];
}
