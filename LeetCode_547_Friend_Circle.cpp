/*
  547. Friend Circles
  There are N students in a class. Some of them are friends, while some are not.
  Their friendship is transitive in nature. For example, if A is a direct friend of B,
  and B is a direct friend of C, then A is an indirect friend of C. And we defined a
  friend circle is a group of students who are direct or indirect friends.

  Given a N*N matrix M representing the friend relationship between students in the class.
  If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not.
  And you have to output the total number of friend circles among all the students.

  Example 1:
  Input: 
  [[1,1,0],
  [1,1,0],
  [0,0,1]]
  Output: 2
  Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
  The 2nd student himself is in a friend circle. So return 2.

  Example 2:
  Input: 
  [[1,1,0],
  [1,1,1],
  [0,1,1]]
  Output: 1
  Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
  so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
 */

class Solution {
  int find( vector<int> groups, int i ) {
    while( i != groups[i] )
      i = groups[i];
    return i;
  }
public:
  int findCircleNum( vector<vector<int>>& M ) {
    int n = M.size();
        
    vector<int> groups(n); // 0,1,...n-1 groups
    for( int i=0; i<n; i++ )
      groups[i] = i; // initially point to itself
        
        
    unordered_map<int, int> studentToGroup;
    for( int i=0; i < n; i++ )
      for( int j=0; j < n; j++ )
	if( M[i][j] == 1 ) {
	  if( studentToGroup.find(j) != studentToGroup.end() ) {
	    studentToGroup[j] = i;
	  } else {
	    // Union
	    int root1 = find( groups, i );
	    int root2 = find( groups, j );
	    groups[root2] = root1;
	  }
	}
        
    int result = 0;
    for( int i=0; i < n; i++ )
      if( groups[i] == i ) result++;
        
    return result;
  }
};
