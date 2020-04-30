/*
895. Maximum Frequency Stack**
Implement FreqStack, a class which simulates the operation of a stack-like data structure.
  FreqStack has two functions:
  push(int x), which pushes an integer x onto the stack.
  pop(), which removes and returns the most frequent element in the stack.
  If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.
  Input: 
  ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
  [[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
  Output: [null,null,null,null,null,null,null,5,7,5,4]
  Explanation:
  After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:

  pop() -> returns 5, as 5 is the most frequent.
  The stack becomes [5,7,5,7,4].

  pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
  The stack becomes [5,7,5,4].

  pop() -> returns 5.
  The stack becomes [5,7,4].

  pop() -> returns 4.
  The stack becomes [5,7].
  Solution: 1

*/

//Using Buckets of frequency
  /* Note: Element 'x' with frequency 'n' gets added to add all buckets
         from freq '1' to 'n'. Hash table keep track of frequency of 'x'.
         Each Bucket acts like a stack. No gets added at the top and removed
         from top. When stack is empty it's removed from bucket. */

class FreqStack {
  unordered_map<int,int> hash;      /* number -> frequency map */
  vector< list<int> > freqBucket;   /* buckets to hold numbers */
public:
  FreqStack() {
    freqBucket.push_back( {0} ); // dummy bucket to hold 0 frequency
  }
    
  void push( int x ) {
    if( hash.find(x) == hash.end() ) {
      // add x to bucket with frequency 1
      if( freqBucket.size() == 1 )
	freqBucket.push_back( {x} );
      else
	freqBucket[1].push_front(x);
      hash.insert( { x, 1 } );
    } else {
      ++hash[x]; // update the frequency
      if( freqBucket.size() == hash[x] )
	freqBucket.push_back( {x} );
      else
	freqBucket[hash[x]].push_front( x );
    }
  }
    
  int pop() {
    // pop the first element from last bucket
    int x = *freqBucket.back().begin();
    freqBucket.back().pop_front();

    // remove the bucket if size == 0
    int freq = hash[x];
    if( freqBucket[freq].size() == 0 )
      freqBucket.pop_back();

    // remove entry from hash table if freq == 0
    --hash[x];
    if( hash[x] == 0 )
      hash.erase(x);
    return x;
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */

//Using Max Heap
/* Maintain a maxHeap ordered by frequency, followed by position in push order.
   Note: Heap contains one entry for each frequency of 'x'.*/
class FreqStack {
  struct Node {
    int x, freq, pos;
    Node( int _x, int _freq, int _pos ) : x(_x), freq(_freq), pos(_pos){}
  };
    
  struct comp {
    bool operator()( Node *n1, Node *n2 ) {
      if( n1->freq != n2->freq ) 
	return n2->freq > n1->freq;
      return n2->pos > n1->pos;
    }  
  };
    
  int count;
  unordered_map<int,int> hash; // element to frequency map
  priority_queue< Node*, vector<Node*>, comp > maxHeap;

public:
  FreqStack() { this->count = 0; }
    
  void push( int x ) {
    if( hash.find(x) == hash.end() )
      hash.insert( {x,0} );       
    ++count;
    ++hash[x];
    maxHeap.push( new Node( x, hash[x], count ) );
  }
    
  int pop() {
    // remove the top from max heap and reduce frequency of x
    int x = maxHeap.top()->x; maxHeap.pop();
    if( hash[x] == 1 )
      hash.erase(x);
    else
      --hash[x];
    return x;
        
  }
};
