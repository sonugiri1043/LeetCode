/*
  378. Kth Smallest Element in a Sorted Matrix

  Given a n x n matrix where each of the rows and columns are sorted in ascending order,
  find the kth smallest element in the matrix.

  Note that it is the kth smallest element in the sorted order, not the kth distinct element.
  Example:
  matrix = [
  [ 1,  5,  9],
  [10, 11, 13],
  [12, 13, 15]
  ],
  k = 8,
  return 13.
  Note:
  You may assume k is always valid, 1 ≤ k ≤ n2.
 */

/*
  Two approaches:
  1. Using heap
  - Same as merging k sorted arrays. We push first col (with index i,j & value ) to heap 
  - take out the top and push the next element in that row
  - Repeat the 2nd step for k times.
 */

class Solution {
  struct numAndIndex {
    int i, j, value;
    numAndIndex( int i, int j, int v ) : i(i), j(j), value(v) {}
  };
    
  struct comparator {
    bool operator()( const numAndIndex *i1, const numAndIndex *i2 ) {
      return i1->value > i2->value;    
    }  
  };
    
public:
  int kthSmallest( vector<vector<int>>& matrix, int k ) {
    priority_queue< numAndIndex*, vector<numAndIndex*>, comparator> minHeap;
    // put first column to heap
    size_t n = matrix.size();
    for( int i=0; i<n; ++i ) {
      minHeap.push( new numAndIndex( i, 0, matrix[i][0] ) );    
    }
        
    numAndIndex *top;
    for( int i=0; i<k; ++i ) {
      top = minHeap.top(); minHeap.pop();
      if( top->j == n - 1 ) continue; // no more elements left in this row
            
      minHeap.push( new numAndIndex( top->i, top->j + 1,
				     matrix[top->i][top->j + 1 ] ) );
    }
    return top->value;
  }
};

/*
  Binary Search
  - At each step we reduce the search range.
  - We count the number of elements smaller than mid and adjust low/high accordingly.
 */

class Solution {
public:
  int kthSmallest( vector<vector<int>>& matrix, int k ) {
    size_t n = matrix.size();
    int low = matrix[0][0], high = matrix[n-1][n-1], mid;
    while( low < high ) {
      mid = low + (high - low)/2;
      // get number of element in each row smaller than mid
      int count = 0, j = n-1;
      for( int i=0; i<n; ++i ) {
	while( j >= 0 && matrix[i][j] > mid ) j--;
	count += j+1;
      }
      if( k > count ) low = mid+1;
      else high = mid;
    }
    return low;
  }
};
