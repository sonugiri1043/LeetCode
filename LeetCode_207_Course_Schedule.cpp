/*
  207.
  There are a total of n courses you have to take, labeled from 0 to n-1.
  Some courses may have prerequisites, for example to take course 0 you
  have to first take course 1, which is expressed as a pair: [0,1]

  Given the total number of courses and a list of prerequisite pairs,
  is it possible for you to finish all courses?

  Example 1:
  Input: 2, [[1,0]] 
  Output: true
  Explanation: There are a total of 2 courses to take. 
  To take course 1 you should have finished course 0. So it is possible.

  Example 2:
  Input: 2, [[1,0],[0,1]]
  Output: false
  Explanation: There are a total of 2 courses to take. 
  To take course 1 you should have finished course 0, and to take course 0
  you should also have finished course 1. So it is impossible.

  Note:
  The input prerequisites is a graph represented by a list of edges, not
  adjacency matrices. Read more about how a graph is represented.
  You may assume that there are no duplicate edges in the input
  prerequisites.
 */

/* Graph Node */
struct Node {
  int course;
  unordered_set<Node*> outEdge;
  int inDegree;
  Node( int course ) : course( course ), inDegree(0) {}
};

/*
  Each course represent a node in a graph.
  A directed edge goes from node b to node a for every dependency [a,b].
  
  A cycle in DAG means that course can't be taken with this set of pre-requistes.
  To delect cycle we use topological sorting.
*/
class Solution {
public:
  bool canFinish( int numCourses, vector<vector<int>> &prerequisites ) {
    vector<Node*> nodes;
    for( int i=0; i < numCourses; i++ ) {
      nodes.push_back( new Node( i ) );
    }

    for( auto edge : prerequisites ) {
      nodes[ edge[1] ]->outEdge.insert( nodes[ edge[0] ] );
      nodes[ edge[0] ]->inDegree++;
    }
        
    // queue has nodes with inDegree = 0
    queue<Node*> q;
    for( auto node : nodes ) {
      if( node->inDegree == 0 ) {
	q.push( node );
      }
    }
        
    int visitedCount = 0;
    Node *curr = NULL;
    while( !q.empty() ) {
      curr = q.front(); q.pop();
      for( auto neighbour : curr->outEdge ) {
	--neighbour->inDegree;
	if( neighbour->inDegree == 0 ) {
	  q.push( neighbour );
	}
      }
      visitedCount++;
    }
    if( visitedCount == numCourses ) {
      return true;
    }
    return false;
  }
};/* Graph Node */
struct Node {
  int course;
  unordered_set<Node*> outEdge;
  int inDegree;
  Node( int course ) : course( course ), inDegree(0) {}
};

/*
  Each course represent a node in a graph.
  A directed edge goes from node b to node a for every dependency [a,b].
  
  A cycle in DAG means that course can't be taken with this set of pre-requistes.
  To delect cycle we use topological sorting.
*/
class Solution {
public:
  bool canFinish( int numCourses, vector<vector<int>> &prerequisites ) {
    vector<Node*> nodes;
    for( int i=0; i < numCourses; i++ ) {
      nodes.push_back( new Node( i ) );
    }

    for( auto edge : prerequisites ) {
      nodes[ edge[1] ]->outEdge.insert( nodes[ edge[0] ] );
      nodes[ edge[0] ]->inDegree++;
    }
        
    // queue has nodes with inDegree = 0
    queue<Node*> q;
    for( auto node : nodes ) {
      if( node->inDegree == 0 ) {
	q.push( node );
      }
    }
        
    int visitedCount = 0;
    Node *curr = NULL;
    while( !q.empty() ) {
      curr = q.front(); q.pop();
      for( auto neighbour : curr->outEdge ) {
	--neighbour->inDegree;
	if( neighbour->inDegree == 0 ) {
	  q.push( neighbour );
	}
      }
      visitedCount++;
    }
    if( visitedCount == numCourses ) {
      return true;
    }
    return false;
  }
};/* Graph Node */
struct Node {
  int course;
  unordered_set<Node*> outEdge;
  int inDegree;
  Node( int course ) : course( course ), inDegree(0) {}
};

/*
  Each course represent a node in a graph.
  A directed edge goes from node b to node a for every dependency [a,b].
  
  A cycle in DAG means that course can't be taken with this set of pre-requistes.
  To delect cycle we use topological sorting.
*/
class Solution {
public:
  bool canFinish( int numCourses, vector<vector<int>> &prerequisites ) {
    vector<Node*> nodes;
    for( int i=0; i < numCourses; i++ ) {
      nodes.push_back( new Node( i ) );
    }

    for( auto edge : prerequisites ) {
      nodes[ edge[1] ]->outEdge.insert( nodes[ edge[0] ] );
      nodes[ edge[0] ]->inDegree++;
    }
        
    // queue has nodes with inDegree = 0
    queue<Node*> q;
    for( auto node : nodes ) {
      if( node->inDegree == 0 ) {
	q.push( node );
      }
    }
        
    int visitedCount = 0;
    Node *curr = NULL;
    while( !q.empty() ) {
      curr = q.front(); q.pop();
      for( auto neighbour : curr->outEdge ) {
	--neighbour->inDegree;
	if( neighbour->inDegree == 0 ) {
	  q.push( neighbour );
	}
      }
      visitedCount++;
    }
    if( visitedCount == numCourses ) {
      return true;
    }
    return false;
  }
};
