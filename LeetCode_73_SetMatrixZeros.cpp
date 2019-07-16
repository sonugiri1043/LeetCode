/*
  https://leetcode.com/problems/set-matrix-zeroes/

  73. Set Matrix Zeroes
  Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

  Example 1:
  
  Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
 */


  class Solution {
  public:
    void setZeroes(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int n = 0;
      if( m ) n = matrix[0].size();
        
      // we use 1st row and 1st column as marker
      // set true when 1st row and 1st column need to be set to zero
      bool row0 = false;
      bool col0 = false;
        
      for( int i = 0; i < m; i++ ) {
	for( int j = 0; j < n; j++ ) {
	  if( matrix[i][j] == 0 ) {
	    matrix[0][j] = 0;
	    matrix[i][0] = 0;
	    if( i == 0 ) {
	      row0 = true;
	    }
	    if( j == 0 ) {
	      col0 = true;
	    }
	  }
	}
      }
        
      for( int i = 1; i < m; i++ ) {
	for( int j = 1; j < n; j++ ) {
	  if( matrix[0][j] == 0 || matrix[i][0] == 0 ) {
	    matrix[i][j] = 0;
	  }
	}
      }
      if( row0 ) {
	// set row zero  to zero
	for( int j = 0; j < n; j++)
	  matrix[0][j] = 0;
      }
      if( col0 ) {
	// set column 0 to zero
	for( int i=0; i < m; i++ ) {
	  matrix[i][0] = 0;
	}
      }
    }
  };
