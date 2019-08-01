/*
  49. Group Anagrams

  Given an array of strings, group anagrams together.
  Example:
  Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
  Output:
  [
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
  ]
  Note:
  All inputs will be in lowercase.
  The order of your output does not matter.
 */

class Solution {
public:
  vector<vector<string>> groupAnagrams( vector<string>& strs ) {
    unordered_map< string, vector<string> > strToGroupMap;
    for( auto s : strs ) {
      string tmp = s;
      sort( tmp.begin(), tmp.end() );
      strToGroupMap[tmp].push_back( s );
    }
    vector< vector<string> > groups;
    for( auto group : strToGroupMap ) {
      groups.push_back( group.second );
    }
    return groups;
  }
};
