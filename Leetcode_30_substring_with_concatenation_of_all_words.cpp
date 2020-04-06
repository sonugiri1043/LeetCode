/*
  You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

 

Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
Example 2:

Input:
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
Output: []
 */

class Solution {
public:
  vector<int> findSubstring( string s, vector<string>& words ) {
    vector<int> startIndex;
    if( words.size() == 0 ) return startIndex;
        
    unordered_map<string, int> wordsFreq, wordsFreqInS;
    for( auto word : words ) wordsFreq[word]++;
        
    int wordSize = words[0].length();
    int windowSize = words.size() * wordSize;
    // keep a sliding window of 'windowSize'
    for( int windowEnd=windowSize-1; windowEnd < s.length(); windowEnd++ ) {
      int windowStart = windowEnd - windowSize + 1;
      wordsFreqInS.clear(); // reset the table
            
      // build wordFreqInS table for each window
      for( int i=windowStart; i <= windowEnd; i += wordSize ) {
	string word = s.substr( i, wordSize );
	if( wordsFreq.find( word ) != wordsFreq.end() )
	  wordsFreqInS[ word ]++;
	else
	  break;
      }
      // if window is valid
      if( wordsFreq == wordsFreqInS ) {
	startIndex.push_back( windowStart );
      }
    }
    return startIndex;
  }
};
