/*
  118. Pascal's Triangle

  Given a non-negative integer numRows, generate the first numRows
  of Pascal's triangle.
   In Pascal's triangle, each number is the sum of the two numbers
  directly above it.

  Example:
  Input: 5
  Output:
  [
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
 ]
 */

class Solution {
public:
  vector<vector<int>> generate( int numRows ) {    
    vector< vector<int> > result;
    vector<int> prevRow = {1}, currRow;
    int n = 1;
    while( n <= numRows ) {
      n++;
      result.push_back( prevRow );
            
      currRow.push_back(1);
      for( int i=1; i < prevRow.size(); ++i ) {
	currRow.push_back( prevRow[i-1] + prevRow[i] );
      }
      currRow.push_back( 1 );
            
      prevRow = currRow;
      currRow.clear();
    }
    return result;
  }
};
