/*
Sliding Window Maximum [LeetCode 239]
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
  Follow up:
Could you solve it in linear time?
  Example:
  Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
  Output: [3,3,5,5,6,7] 
  Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7      5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/
 /* The basic idea is to use a deque (buffer) to save all currently potential
    "maximum" elements (i.e. the element in the current k-element window [i-k+1, i],
    and it is larger than the elements after itself). So for each i, we first pop up
    the elements that are no larger than nums[i] from buffer until we find one that
    is larger than nums[i] or the buffer is empty since those elements will be covered
    by nums[i] and can not be a maximum of any k-element window. Then we put nums[i]
    in the buffer. If i>=k-1, we need to ouput the maximum for window [i-k+1, i], which
    is the front element of buffer. At last, we will check if the front element is
    nums[i-k+1], if so, we have to pop it up since it will be out of the window [i-k+2, i+1]
    in the next iteration. Since all the elements will be pushed into/ popped out of
    the buffer only once, so the time complexity is O(N).
  */

vector<int> maxSlidingWindow( vector<int>& nums, int k ) {
  vector<int> result;
  deque<int> dq;
  for( int i=0; i < nums.size(); i++ ) {
    // pop from back till it's less than nums[i] 
    while( !dq.empty() && dq.back() < nums[i] )
      dq.pop_back();

    // add current element to queue
    dq.push_back( nums[i] );

    // remove the front if it's less than equal to nums[i-k+1]
    if( i >= k - 1 ) {
      result.push_back( dq.front() );
      if( dq.front() <= nums[i-k+1] )  dq.pop_front();
    }
  }
  return result;
}
