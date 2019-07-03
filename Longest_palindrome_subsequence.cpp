/*
  L[0,n-1] => longest palindromic sub-sequence from 0 - n-1.
  L[0,n-1] => L[ 1, n-2 ] + 2 if arr[0] == arr[n-1]
              else
	      max{ L[1, n-1], L[ 0, n-2] }
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int max( int a, int b ) {
  return a > b ? a : b;
}

void longestPalindromeSubSeq( string input ) {
  // Initialize
  int size = input.length();
  int arr[ size ][ size ];
  for( int i=0; i < size; ++i ) {
    for( int j=0; j < size; ++j ) {
      arr[i][j] = ( i == j ) ? 1 : 0;
    }
  }

  for( int k=1; k <= size-1; k++ ) {
    /* i -> start index, j -> end index */
    for( int i=0, j=k; i <= size-k-1 && j <= size-1; i++, j++ ) {
      if( input[ i ] == input[j] ) {
	arr[i][j] = 2 + arr[i+1][j-1];
      } else {
	arr[i][j] = max( arr[i+1][j], arr[i][j-1] );
      }
    }
  }
  cout << "Max size: " << arr[0][size-1] << endl;
}

int main() {
  string input = "GEEKS FOR GEEKS";
  longestPalindromeSubSeq( input );
  return 0;
}
