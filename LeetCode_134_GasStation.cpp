/*
  There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

  You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to
  its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
  
  Return the starting gas station's index if you can travel around the circuit once in the clockwise
  direction, otherwise return -1.
  
  Note:
  If there exists a solution, it is guaranteed to be unique.
  Both input arrays are non-empty and have the same length.
  Each element in the input arrays is a non-negative integer.

  https://leetcode.com/problems/gas-station/
 */


// If car starts at A and can not reach B. Any station between A and B can not reach B.
// (B is the first station that A can not reach.)
// If the total number of gas is bigger than the total number of cost. There must be a solution.

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int start(0), total(0), tank(0);
    for( int i=0; i < gas.size(); i++ ) {
      tank += gas[i] - cost[i];
      if( tank < 0 ) {
	start = i+1;
	total += tank;
	tank = 0;
      }
    }
    if( total + tank >= 0 ) {
      return start;
    } else {
      return -1;
    }
  }
};
