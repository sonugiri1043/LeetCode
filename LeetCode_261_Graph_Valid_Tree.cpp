/*
  Given n nodes labeled from 0 to n - 1 and a list of undirected edges
  (each edge is a pair of nodes), write a function to check whether these
  edges make up a valid tree.

  For example:
  Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
  Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

  Note: you can assume that no duplicate edges will appear in edges. Since all
  edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool dfs( int n, vector<vector<int>> adjList ) {
  vector<bool> visited( n, false );
  stack<int> s;
  s.push( 0 );
  visited[ 0 ] = true;
  while( !s.empty() ) {
    int curr = s.top(); s.pop();
    for( auto v : adjList[curr] ) {
      if( !visited[v] ) {
        visited[v] = true;
        s.push( v  );
      }
    }
  }

  for( auto v : visited ) {
    if( !v ) return false;
  }
  return true;
}

bool isValidTree( int noNodes, vector<vector<int>> edges ) {
  int noEdge = edges.size();
  if( noEdge != noNodes - 1 ) {
    return false;
  }

  vector<vector<int>> adjList( noNodes );
  for( auto edge : edges ) {
    adjList[ edge[0] ].push_back( edge[1] );
    adjList[ edge[1] ].push_back( edge[0] );
  }
  return dfs( noNodes, adjList );
}

int main() {
  cout<< isValidTree( 5, {{0, 1}, {0, 2}, {0, 3}, {1, 4}} ) << endl;
  cout<< isValidTree( 5, {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4} }) << endl;
  return 0;
}
