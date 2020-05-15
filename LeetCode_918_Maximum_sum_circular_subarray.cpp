/*
  Maximum Sum Circular Subarray [LeetCode 918]
  Given a circular array C of integers represented by A, find the maximum
  possible sum of a non-empty subarray of C. 
  Here, a circular array means the end of the array connects to the beginning
  of the array. ( Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)
  Also, a subarray may only include each element of the fixed buffer A at most once.

  Approach:
  So there are two cases.
  The first is that the subarray takes only a middle part, and we know how to find the max subarray sum.
  The second is that the subarray takes a part of the head array and a part of the tail array.
  We can transfer this case to the first one.
  The maximum result equals the total sum minus the minimum subarray sum.
  
  Corner case
  Just one to pay attention:
  If all numbers are negative, maxSum = max(A) and minSum = sum(A).
  In this case, max(maxSum, total - minSum) = 0, which means the sum of an empty subarray.
  According to the description, We need to return the max(A), instead of the sum of an empty subarray.
  So we return the maxSum to handle this corner case.
*/

int maxSubarraySumCircular( vector<int>& A ) {
  int total = 0, globalMaxSum = INT_MIN, curMax = 0;
  int globalMinSum = INT_MAX, curMin = 0;
  for( int a : A ) {
    curMax = max( curMax + a, a );
    globalMaxSum = max( globalMaxSum, curMax );
    curMin = min( curMin + a, a );
    globalMinSum = min( globalMinSum, curMin );
    total += a;
  }
  return globalMaxSum > 0 ? max( globalMaxSum, total - globalMinSum ) : globalMaxSum;
}
