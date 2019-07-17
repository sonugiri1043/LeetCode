/*
  https://leetcode.com/problems/min-stack/
  
  155. Min Stack

  Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

  push(x) -- Push element x onto stack.
  pop() -- Removes the element on top of the stack.
  top() -- Get the top element.
  getMin() -- Retrieve the minimum element in the stack.
 
  Example:

  MinStack minStack = new MinStack();
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  minStack.getMin();   --> Returns -3.
  minStack.pop();
  minStack.top();      --> Returns 0.
  minStack.getMin();   --> Returns -2.
*/

class MinStack {
  stack< pair<int, int > > s;

public:
  /** initialize your data structure here. */
  MinStack() {
  }
    
  void push( int x ) {
    if( s.empty() ) {
      s.push( make_pair( x, x ) );
    } else {
      int min = x > s.top().second ? s.top().second : x;
      s.push( make_pair( x, min ) );
    }
  }
    
  void pop() {
    s.pop();
  }
    
  int top() {
    return s.top().first;
  }
    
  int getMin() {
    return s.top().second;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
