/*
  Valid Graph Tree [Leetcode 261]

  Given n nodes labeled from 0 to n - 1 and a list of undirected edges
  ( each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
  
  Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
  Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

  Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected,
  [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 */

/*
If a graph is valid tree, it must follow the two conditions:
1. num of edges = num of nodes - 1
2. There is only 1 Connected Component.

  Other approach:
1. A tree is a graph that doesn't have a cycle.
2. There is only 1 Connected Component.

BFS. When a node is polled from a queue, iterate through its neighbors.
If any of them is visited, there is a cycle.
*/

class Solution {
public:
    bool validTree( int n, vector<vector<int>> &edges ) {
        unordered_map<int, set<int>> adjList;
        for( auto edge : edges ) {
            adjList[edge[1]].insert(edge[0]);
            adjList[edge[0]].insert(edge[1]);
        }
        
        vector<bool> visited( n, false );
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while( !q.empty() ) {
            int curr = q.front(); q.pop();
            for( auto nbr : adjList[curr] ) {
                adjList[nbr].erase(curr);
                if( visited[nbr] ) return false; // cycle detected
                if( !visited[nbr] ) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
            adjList.erase(curr);
        }

        for( auto v : visited )
            if( !v ) return false;
        
        return true;
    }
};
