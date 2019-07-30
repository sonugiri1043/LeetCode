/*
  150. Evaluate Reverse Polish Notation
  Evaluate the value of an arithmetic expression in Reverse Polish Notation.

  Valid operators are +, -, *, /. Each operand may be an integer or another expression.
  Note:
  - Division between two integers should truncate toward zero.
  - The given RPN expression is always valid. That means the expression would always
    evaluate to a result and there won't be any divide by zero operation.

  Example 1:
  Input: ["2", "1", "+", "3", "*"]
  Output: 9
  Explanation: ((2 + 1) * 3) = 9
 */

class Solution {
public:
  int evalRPN( vector<string>& tokens ) {
    stack<int> s;
    int op1;
    int op2;
    for( auto t : tokens ) {
      if( t == "+" || t == "*" || t == "/" || t == "-" ) {
	op1 = s.top(); s.pop();
	op2 = s.top(); s.pop();
	if( t == "+" ) s.push( op2 + op1 );
	if( t == "-" ) s.push( op2 - op1 );
	if( t == "*" ) s.push( op2 * op1 );
	if( t == "/" ) s.push( op2 / op1 );
      } else {
	s.push( stoi( t ) );
      }
    }
    return s.top();
  }
};
