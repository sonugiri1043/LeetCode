/*
  Number of Matching Subsequences [LeetCode 792]
  Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

  Example:
  Input: 
  S = "abcde"
  words = ["a", "bb", "acd", "ace"]
  Output: 3

  Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
  Note:
  All words in words and S will only consist of lowercase letters.
*/

/*
  Create a map that stores indices for each character a-z in S
  Then for each word, do a binary search for next index for current character in word 
  that is greater than the index we last found for the last character.
  If it doesn't exist, word doesn't exist, otherwise continue to search for word */

int numMatchingSubseq( string S, vector<string>& words ) {
  unordered_map< char, vector<int> > charToIndex;
  for( int i=0; i < S.size(); i++ )
    charToIndex[ S[i] ].push_back( i );
            
  int result = 0;
  for( auto word : words ) {
    int isSubSeq = true;
    int pos = -1;
    for( auto c : word ) {
      auto it = upper_bound( charToIndex[c].begin(), charToIndex[c].end(), pos );
      if( it == charToIndex[c].end() )
	isSubSeq = false;
      else 
	pos = *it;
    }
    
    if( isSubSeq ) ++result;
  }
  return result;
}
