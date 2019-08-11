/*
  8. String to Integer (atoi)

  Implement atoi which converts a string to an integer.

  The function first discards as many whitespace characters as necessary
  until the first non-whitespace character is found. Then, starting from
  this character, takes an optional initial plus or minus sign followed
  by as many numerical digits as possible, and interprets them as a
  numerical value.

  The string can contain additional characters after those that form the
  integral number, which are ignored and have no effect on the behavior of
  this function.

  If the first sequence of non-whitespace characters in str is not a valid
  integral number, or if no such sequence exists because either str is empty
  or it contains only whitespace characters, no conversion is performed.

  If no valid conversion could be performed, a zero value is returned.
  Note:
  Only the space character ' ' is considered as whitespace character.
  Assume we are dealing with an environment which could only store integers
  within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical
  value is out of the range of representable values, INT_MAX (231 − 1) or
  INT_MIN (−231) is returned.

  Example 1:
  Input: "42"
  Output: 42

  Example 2:
  Input: "   -42"
  Output: -42
  Explanation: The first non-whitespace character is '-', which is the minus
  sign.
  Then take as many numerical digits as possible, which gets 42.
  
  Example 3:
  Input: "4193 with words"
  Output: 4193
  Explanation: Conversion stops at digit '3' as the next character is not a
  numerical digit.

  Example 4:
  Input: "words and 987"
  Output: 0
  Explanation: The first non-whitespace character is 'w', which is not a
  numerical digit or a +/- sign. Therefore no valid conversion could be
  performed.

  Example 5:
  Input: "-91283472332"
  Output: -2147483648
  Explanation: The number "-91283472332" is out of the range of a 32-bit
  signed integer.
  Thefore INT_MIN (−231) is returned.
 */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
  int myAtoi( string str ) {
    int index = 0;
    long result_str = 0;
        
    // Remove the space before the number
    while( index < str.length() && str[index] == ' ' ) {
      index++;
    }
        
    // Check the first non-space char: -, +, 0~9
    if( index == str.length() || ( str[index] != '-' && str[index] != '+' && ( str[index] < '0' || str[index] > '9' ) ) ) {
      return 0;
    }
        
    // Check the sign of the number
    if (str[index] == '-' || str[index] == '+') {
      result_str += str[index];
      index++;
    }
        
    // If the result is a number
    bool is_num = false;
        
    // Check the first char (after the sign) is a number
    if (index != str.length() && str[index] >= 48 && str[index] <= 57) {
      is_num = true;
      result_str += str[index];
      index++;
    }
        
    // Add the char until it is not a number
    for (;index != str.length(); ++index) {
      if (str[index] >= 48 && str[index] <= 57) {
	result_str += str[index];
      }else{
	break;
      }
    }
        
    // From string to long
    long result_num;
    stringstream s;
    s << result_str;
    s >> result_num;
        
    // Check for overflow
    if (result_num < -2147483648) {
      result_num = -2147483648;
    }
    if (result_num  > 2147483647) {
      result_num = 2147483647;
    }
    return int(result_num);
  }
};
