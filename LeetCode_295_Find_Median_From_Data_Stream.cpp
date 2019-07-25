class MedianFinder {
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;
    
public:
  MedianFinder() {}
    
  void addNum( int num ) {
    if( maxHeap.size() == 0 ) {
      maxHeap.push( num );
      return;
    }
    if( minHeap.size() == 0 ) {
      if( num > maxHeap.top() ) {
	minHeap.push( num );
      } else {
	minHeap.push( maxHeap.top() );
	maxHeap.pop();
	maxHeap.push( num );
      }
      return;
    }
        
    if( maxHeap.size() == minHeap.size() ) {
      if( num > maxHeap.top() && num < minHeap.top() ) {
	maxHeap.push( num );
      } else if( num < maxHeap.top() ) {
	maxHeap.push( num );
      } else {
	maxHeap.push( minHeap.top() );
	minHeap.pop();
	minHeap.push( num );
      }
    } else {
      if( num > maxHeap.top() && num < minHeap.top() ) {
	minHeap.push( num );
      } else if( num < maxHeap.top() ) {
	minHeap.push( maxHeap.top() );
	maxHeap.pop();
	maxHeap.push( num );
      } else {
	minHeap.push( num );
      }
    }
  }
    
  double findMedian() {
    if( maxHeap.size() == 0 ) return 0;
    if( minHeap.size() == 0 ) return maxHeap.top();
        
    if( maxHeap.size() == minHeap.size() ) 
      return ( maxHeap.top() + minHeap.top() )/2.0;
    return maxHeap.top();
  }
};
