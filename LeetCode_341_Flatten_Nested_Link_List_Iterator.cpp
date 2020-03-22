/*
  341. Flatten Nested List Iterator
  Given a nested list of integers, implement an iterator to flatten it.

  Each element is either an integer, or a list -- whose elements may also
  be integers or other lists.

  Example 1:
  Input: [[1,1],2,[1,1]]
  Output: [1,1,2,1,1]
  Explanation: By calling next repeatedly until hasNext returns false, 
  the order of elements returned by next should be: [1,1,2,1,1].

  Example 2:
  Input: [1,[4,[6]]]
  Output: [1,4,6]
  Explanation: By calling next repeatedly until hasNext returns false, 
  the order of elements returned by next should be: [1,4,6].
 */

/* The same idea as a DFS, the only tricky part probably is you have to find a value node to claim there is next. And to do that, you have to look through all the nodes in the worst case in the entire graph. So you just keep going until you find a value node; if you can't, there is no next */

class NestedIterator {
  stack<NestedInteger> s;    
public:
  NestedIterator( vector<NestedInteger> &nestedList ) {
    for( int i=nestedList.size()-1; i >=0; i-- )
      s.push( nestedList[i] );
  }

  int next() {
    int res = s.top().getInteger();
    s.pop();
    return res;  
  }

  bool hasNext() {
    while( !s.empty() ) {
      NestedInteger top = s.top();
      if( top.isInteger() )  {
	return true;
      } else {
	vector<NestedInteger> lists = top.getList();
	s.pop();
	for( int i=lists.size()-1; i>=0 ; i-- )
	  s.push( lists[i] );
      }
    }
    return false;
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
