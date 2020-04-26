/*
  703. Kth Largest Element in a Stream
  Design a class to find the kth largest element in a stream. Note that it is the
  kth largest element in the sorted order, not the kth distinct element.
 */


// We can build a MinHeap that contains only k largest elements.
class KthLargest {
  priority_queue<int,vector<int>, greater<int>> minHeap;
  int capacity;
public:
  KthLargest( int k, vector<int>& nums ) {
    this->capacity = k;
    for( auto num : nums ) {
      minHeap.push(num);
      if( minHeap.size() > k )  minHeap.pop();
    }
  }
    
  int add( int val ) {
    minHeap.push( val );
    if( minHeap.size() > this->capacity )
      minHeap.pop();
    return minHeap.top();
  }
};

