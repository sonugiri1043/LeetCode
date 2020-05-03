/*
  130. Surrounded Regions
  Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
  A region is captured by flipping all 'O's into 'X's in that surrounded region.

  Example:
  X X X X
  X O O X
  X X O X
  X O X X

  After running your function, the board should be:
  X X X X
  X X X X
  X X X X
  X O X X
  Explanation:
  Surrounded regions shouldn’t be on the border, which means that any 'O' on
  the border of the board are not flipped to 'X'. Any 'O' that is not on the
  border and it is not connected to an 'O' on the border will be flipped to
  'X'. Two cells are connected if they are adjacent cells connected horizontally
  or vertically.
 */

class Solution {
public:
  /*
    First, check the four border of the matrix. If there is a element is
    'O', alter it and all its neighbor 'O' elements to '1'.
    Then ,alter all the 'O' to 'X'
    At last,alter all the '1' to 'O'

    For example:
         X X X X           X X X X             X X X X
         X X O X  ->       X X O X    ->       X X X X
         X O X X           X 1 X X             X O X X
         X O X X           X 1 X X             X O X X
  */
    
  void bfs( vector<vector<char>>& board, int i, int j, int n, int m ) {
    queue<pair<int,int>> q;
    q.push( {i,j} );
    board[i][j] = '1';
    while( !q.empty() ) {
      auto curr = q.front(); q.pop();
      i = curr.first;
      j = curr.second;
            
      if( i-1 >= 0 && board[i-1][j] == 'O' ) {
	q.push( {i-1, j} );
	board[i-1][j] = '1';
      }
      if( j-1 >= 0 && board[i][j-1] == 'O' ) {
	q.push( {i, j-1} );
	board[i][j-1] = '1';
      }
      if( i+1 < n && board[i+1][j] == 'O' ) {
	q.push( {i+1, j} );
	board[i+1][j] = '1';
      }
      if( j+1 < m && board[i][j+1] == 'O' ) {
	q.push( {i, j+1} );
	board[i][j+1] = '1';
      }
    }
  }
    
  void solve( vector<vector<char>>& board ) {
    int n = board.size();
    if( n == 0 ) return;
    int m = board[0].size();
        
    // bfs on boundary elements if == "O"
    for( int i=0; i<n; i++ )
      for( int j=0; j<m; j++ ) 
	if( ( i==0 || j==0 || i==n-1 || j==m-1 ) &&
	    board[i][j] == 'O' )
	  bfs( board, i, j, n, m );

    for( int i=0; i < n; i++ )
      for( int j=0; j < m; j++ )
	if( board[i][j] == '1' )
	  board[i][j] = 'O';
	else
	  board[i][j] = 'X';
  }
};
