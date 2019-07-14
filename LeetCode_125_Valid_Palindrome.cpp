/*
  125. Valid Palindrome

  https://leetcode.com/problems/valid-palindrome/

  Given a string, determine if it is a palindrome, considering only alphanumeric characters
  and ignoring cases.

  Note: For the purpose of this problem, we define empty string as valid palindrome.

  Example 1:
  Input: "A man, a plan, a canal: Panama"
  Output: true

  Example 2:
  Input: "race a car"
  Output: false
 */
class Solution {
public:
  bool isPalindrome(string s) {
    // get new string without space and all lowercase
    string newStr = "";
    for( int i = 0; i < s.length(); i++ ) {
      if( 'a' <= s[i] && s[i] <= 'z' ) {
	newStr += s[i];   
      }
      if( s[i] <= 'Z' && s[i] >= 'A') {
	newStr += s[i] - ('Z' - 'z');
      }
      if( s[i] <= '9' && s[i] >= '0' ) {
	newStr += s[i];
      } 
    }
        
    bool isPalindrome = true;
    int begin = 0;
    int end = newStr.length() - 1;
    while( begin < end ) {
      if( newStr[begin] != newStr[end] ) {
	isPalindrome = false;
	break;
      }
      begin++;
      end--;
    }
    return isPalindrome;
  }
};
