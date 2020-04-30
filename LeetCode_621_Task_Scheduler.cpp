/*
Task Scheduler [Leetcode 621]**

Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
*/

The idea used here is similar to - https://leetcode.com/problems/rearrange-string-k-distance-apart
We need to arrange the characters in string such that each same character is K distance apart, where distance in this problems is time b/w two similar task execution.
Idea is to add them to a priority Q and sort based on the highest frequency.
  And pick the task in each round of 'n' with highest frequency. As you pick the task, decrease the frequency, and put them back after the round.
  class Solution {
  public:
    int leastInterval( vector<char>& tasks, int n ) {
      // create task to frequency hash table 'taskFreq'
      unordered_map<char, int> taskFreq;
      for( auto task : tasks ) 
	++taskFreq[task];
        
      // create a maxHeap from taskFreq
      priority_queue<pair<int, char>> maxHeap;
      for( auto p : taskFreq )
	maxHeap.push( { p.second, p.first } );
        
      // Try to fill window 0 - n with different tasks, otherwise empty slots.
      // similar to placing same task task n distance apart ( i, i+n+1 )
      string taskOrder = "";
      while( !maxHeap.empty() ) {
	queue< pair<int, char> > tmpQueue;
	int i = n+1;
	while( i-- > 0 ) {
	  if( maxHeap.empty() ) {
	    /* no more task to be executed in this window
	       add idle window since we have pending task for next window */
	    if( !tmpQueue.empty() )
	      taskOrder += "0"; 
	  } else {
	    // most frequency task
	    auto p = maxHeap.top(); maxHeap.pop();
	    taskOrder += p.second;
	    // decrease frequency, meaning it got executed
	    --p.first;
	    // collect eligible task to add back to maxHeap
	    if( p.first > 0 ) tmpQueue.push( p );
	  }
	}

	// add pending tasks to maxHeap
	while( !tmpQueue.empty() ){
	  maxHeap.push( tmpQueue.front() );
	  tmpQueue.pop();
	}
      }
      return taskOrder.length();
    }
  };
