/*
  542. 01 Matrix
  Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
  The distance between two adjacent cells is 1.

  Example 1:
  Input:
  [[0,0,0],
  [0,1,0],
  [0,0,0]]

 Output:
 [[0,0,0],
 [0,1,0],
 [0,0,0]]
 */

// approach 1 using BFS
vector<vector<int>> updateMatrix( vector<vector<int>>& matrix ) {
  int m = matrix.size(), n = matrix[0].size();
  vector<vector<int>> result( m, vector<int>( n, m+n )); // max value
        
  queue< pair<int, int> > q;
  for( int i=0; i < m; i++ )
    for( int j=0; j < n; j++ )
      if( matrix[i][j] == 0 ) {
	q.push( make_pair( i, j ) );
	result[i][j] = 0;
      }
    
  while( !q.empty() ) {
    auto p = q.front(); q.pop();
    int i = p.first, j = p.second, dist = 1 + result[i][j];
    if( i + 1 < m && result[i+1][j] > dist ) {
      result[i+1][j] = dist;
      q.push( make_pair(i + 1, j ) );
    }
    if( i - 1 >= 0 && result[ i-1 ][ j ] > dist ) {
      result[i-1][j] = dist;
      q.push( make_pair( i - 1, j ) );
    }
    if( j + 1 < n && result[ i ][ j+1 ] > dist  ) {
      result[i][j+1] = dist;
      q.push( make_pair( i, j + 1 ) );
    }
    if( j- 1 >= 0 &&  result[i][ j-1 ] > dist ) {
      result[i][j] = dist;
      q.push( make_pair( i, j - 1 ) );
    }
  }
  return result;
}

// approach 2
vector<vector<int>> updateMatrix( vector<vector<int>>& matrix ) {
  int m = matrix.size(), n = matrix[0].size();
  vector<vector<int>> result( m, vector<int>( n, m+n )); // max value can be m+n
        
  for( int k = 0; k <= 1; k++ ) {
    for( int i= k? 0:m-1; k? i < m : i >= 0; k? i++ : i-- ) {
	for( int j=k ? 0:n-1; k ? j < n : j >= 0; k? j++ : j-- ) {
	    if( matrix[i][j] == 0 )
	      result[i][j] = 0;
	    else {
	      if( i-1 >= 0 )
		result[i][j] = min( result[i][j], result[i-1][j]+1 );
	      if( j-1 >= 0 )
		result[i][j] = min( result[i][j], result[i][j-1]+1 );
	      if( i+1 < m )
		result[i][j] = min( result[i][j], result[i+1][j]+1 );
	      if( j+1 < n )
		result[i][j] = min( result[i][j], result[i][j+1]+1 );
	    }
	  }
	       }
      }
	   return result;
	 }
