/*
  https://leetcode.com/problems/spiral-matrix/

  54. Spiral Matrix

  Given a matrix of m x n elements (m rows, n columns), return all elements of the
  matrix in spiral order.

  Example 1:
  Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

  Example 2:
  Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
  Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if( m == 0 ) return {};
    int n = matrix[0].size();
        
    vector<int> result;
    int colMin = 0;
    int colMax = n-1;
    int rowMin = 0;
    int rowMax = m-1;
    int count = 0;
    while( rowMin <= rowMax && colMin <= colMax ) {
      for( int j = colMin; j <= colMax && count < m*n; j++ ) {
	result.push_back( matrix[rowMin][j] );
	count++;
      }
      rowMin++;
      for( int i = rowMin; i <= rowMax && count < m*n; i++ ) {
	result.push_back( matrix[i][colMax] );
	count++;
      }
      colMax--;
      for( int j = colMax; j >= colMin && count < m*n; j-- ) {
	result.push_back( matrix[rowMax][j] );
	count++;
      }
      rowMax--;
      for( int i= rowMax; i >= rowMin && count < m*n; i-- ) {
	result.push_back( matrix[i][colMin] );
	count++;
      }
      colMin++;
    }
    return result;
  }
};
