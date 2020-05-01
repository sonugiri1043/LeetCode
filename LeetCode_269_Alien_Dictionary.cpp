/*
  Alien Dictionary [LeetCode 269]
  There is a new alien language which uses the latin alphabet. However, the order among
  letters is unknown to you. You receive a list of non-empty words from the dictionary,
  where words are sorted lexicographically by the rules of this new language. Derive the
  order of letters in this language.

  Example 1:
  Given the following words in dictionary,
  [ "wrt",
  "wrf",
  "er",
  "ett",
  "rftt" ]
  The correct order is: "wertf".

  Example 2:
  Given the following words in dictionary,
  [ "z",
  "x" ]
  The correct order is: "zx".

  Example 3:
  Given the following words in dictionary,
  [ "z",
  "x",
  "Z" ]

  The order is invalid, so return "".
*/

/*
  Topological sort:
  Build graph: 
  a map of character -> set of character.
  Also get in-degrees for each character. In-degrees will be a map of character -> integer.

  Topological sort:
  Loop through in-degrees. Offer the characters with in-degree of 0 to queue.
  While queue is not empty:
  Poll from the queue. Append a character to the result string.
  Decrease the in-degree of polled character's children by 1.
  If any child's in-degree decreases to 0, offer it to queue.
  At last, if the result string's length is less than the number of vertices, that means there is a cycle in my graph. The order is invalid.
  
  Say the number of characters in the dictionary (including duplicates) is n. Building the graph takes O(n). Topological sort takes O(V + E). V <= n. E also can't be larger than n. So the overall time complexity is O(n).
*/

    class Solution {
    public:
      void buildGraph( vector<string> &words, map<char,set<char>> &adjList,
		       map<char,int> &indegree ) {
        for( string word : words )
	  for( char c : word )
	    indegree.insert( { c, 0 } );
        
        for( int i = 1; i < words.size(); i++ ) {
	  string first = words[i - 1];
	  string second = words[i];
	  int length = min( first.length(), second.length() );
	  for( int j = 0; j < length; j++ ) {
	    char parent = first[j];
	    char child = second[j];
	    if( parent != child ) { 
	      if( !adjList[parent].count(child) ) {
		adjList[parent].insert( child );
		indegree[ child ]++;
	      }
	      break;
	    }
	  }
        }
      }
    
      string topologicalSort( map<char,set<char>>& adjList, map<char,int>& indegree ) {
	stack<char> sources;
	for( auto p : indegree )
	  if( p.second == 0 ) sources.push( p.first );

	string order="";
	while( !sources.empty() ) {
	  char curr = sources.top(); sources.pop();
	  order += curr;
	  for( auto nbr : adjList[curr] ) {
	    --indegree[nbr];
	    if( indegree[nbr] == 0 )
	      sources.push(nbr);
	  }
	}
	return order;
      }
    
      string alienOrder( vector<string> &words ) {
        map<char, set<char>> adjList;
        map<char, int> indegree;
        buildGraph( words, adjList, indegree );
        string order = topologicalSort( adjList, indegree );
        return order.length() == indegree.size() ? order : "";
      }
    };
