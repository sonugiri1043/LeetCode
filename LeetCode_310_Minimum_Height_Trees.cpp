/*
  310. Minimum Height Trees
  For an undirected graph with tree characteristics, we can choose any
  node as the root. The result graph is then a rooted tree. Among all
  possible rooted trees, those with minimum height are called minimum height
  trees (MHTs). Given such a graph, write a function to find all the MHTs and
  return a list of their root labels.
 */

/*
  The basic idea is "keep deleting leaves layer-by-layer, the last layer of leaves are left."
  Detailed algo:
  First find all the leaves, then remove them. After removing, some nodes will become new
  leaves. So we can continue removing them. Eventually, there are only 1 or 2 nodes left.
  If there is only one node left, it is the root. If there are 2 nodes, either of them could
  be a possible root.
 */

vector<int> findMinHeightTrees( int n, vector<vector<int>>& edges ) {
  if( n == 1 ) return {0};
        
  // make adjacency List from edges
  vector< unordered_set<int> > adjList(n);
  for( auto edge : edges ) {
    adjList[edge[0]].insert( edge[1] );
    adjList[edge[1]].insert( edge[0] );
  }
        
  // BFS over all nodes with degree 1 (leaf) as source
  vector<int> parents, child;
  for( int i=0; i < n; i++ )
    // push leaf nodes, degree = 1 
    if( adjList[i].size() == 1 )  parents.push_back( i );
        
  while( true ) {
    for( int node : parents ) {
      for( int neighbour : adjList[node] ) {
	adjList[neighbour].erase( node );
	if( adjList[neighbour].size() == 1 ) // new leaf
	  child.push_back( neighbour );
      }
      adjList[node].clear();
    }
    if( child.empty() ) return parents; //last level of leaf
    parents = child;
    child.clear();
  }
  return parents;
}
