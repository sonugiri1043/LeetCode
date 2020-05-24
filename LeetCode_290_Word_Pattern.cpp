/*
  Word Pattern [LeetCode 290]
  Given a pattern and a string str, find if str follows the same pattern.

  Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
  Example:
  Input: pattern = "abba", str = "dog cat cat dog"
  Output: true
  Input:pattern = "abba", str = "dog cat cat fish"
  Output: false
*/
  bool wordPattern( string pattern, string str ) {
    // convert str to vector of string
    istringstream strcin( str );
    string word;
    vector<string> words;
    while( strcin >> word )
      words.push_back(word);

    /* convert pattern to a string of int as follows:
        for "abba" => 1221
	for "abbca" => 12231 */ 
    unordered_map<char, int> p2i;
    int i=0;
    string pat = "";
    for( auto c : pattern ) {
      if( p2i.count(c) == 0 ) {
	i++;
	p2i[c] = i;
      }
      pat += to_string( p2i[c] );   
    }

    // do the same for str
    unordered_map<string, int> str2i;
    i=0;
    string pat1 = "";
    for( auto c : words ) {
      if( str2i.count(c) == 0 ) {
	i++;
	str2i[c] = i;
      }
      pat1 += to_string( str2i[c] );   
    }
    // true if both matches
    return pat1 == pat;  
  }
