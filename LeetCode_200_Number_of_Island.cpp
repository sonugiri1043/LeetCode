/*
  200. Number of Islands

  Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
  An island is surrounded by water and is formed by connecting adjacent lands horizontally
  or vertically. You may assume all four edges of the grid are all surrounded by water.

  Example 1:
  Input:
  11110
  11010
  11000
  00000
  Output: 1

  Example 2:
  Input:
  11000
  11000
  00100
  00011
  Output: 3
 */

class Solution {
  void bfs( vector<vector<char>>& grid, int i, int j, int n, int m ) {
    queue< pair<int, int> > q;
    q.push( make_pair( i, j ) );
    grid[i][j] = '0';
    while( !q.empty() ) {
      pair<int, int> p = q.front(); q.pop();
      if( p.first - 1 >= 0 && grid[p.first-1][p.second] == '1' ) {
	grid[p.first-1][p.second] = '0';
	q.push( make_pair( p.first-1, p.second ) );
      }
      if( p.first + 1 < n && grid[p.first + 1][p.second]  == '1' ) {
	grid[p.first+1][p.second] = '0';
	q.push( make_pair( p.first + 1, p.second ));
      }
      if( p.second-1 >= 0 && grid[p.first][p.second-1] == '1' ) {
	grid[p.first][p.second-1] = '0';
	q.push( make_pair( p.first, p.second-1 ));
      }
      if( p.second + 1 < m && grid[p.first][p.second+1] == '1' ) {
	grid[p.first][p.second+1] = '0';
	q.push( make_pair( p.first, p.second+1 ));
      }
    }
  }
    
public:
  int numIslands( vector<vector<char>>& grid ) {
    int n = grid.size();
    int m = n > 0 ? grid[0].size() : 0;
    int noOfIsland = 0;

    for( int i=0; i < n; i++ ) {
      for( int j=0; j < m; j++ ) {
	if( grid[i][j] == '1' ) {
	  ++noOfIsland;
	  bfs( grid, i, j, n, m );
	}
      }
    }
    return noOfIsland;
  }
};
