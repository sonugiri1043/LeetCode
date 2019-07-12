/*
  14. Longest Common Prefix
  Write a function to find the longest common prefix string amongst an array of strings.
  If there is no common prefix, return an empty string "".

  Example 1:

  Input: ["flower","flow","flight"]
  Output: "fl"
  Example 2:

  Input: ["dog","racecar","car"]
  Output: ""
  Explanation: There is no common prefix among the input strings.
 */

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if( strs.size() == 0 ) {
      return "";
    }
    int minLen = INT_MAX;
    string commonSubStr = "";
    // get the min length of the string among all strings
    for( int i=0; i < strs.size(); i++ ) {
      if( strs[i].length() < minLen ) {
	minLen = strs[i].length();
      }
    }
        
    // check the common part upto minLen
    bool flag = false;
    for( int j = 0; j < minLen; j++ ) {
      char c = strs[0][j];
      for( int i = 1; i < strs.size(); i++ ) {
	if( c != strs[i][j] ) {
	  flag = true;
	  break;
	}
      }
      if( flag ) {
	break;
      }
      commonSubStr += c;
    }
    return commonSubStr;
  }
};
