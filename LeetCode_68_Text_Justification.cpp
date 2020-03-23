/*
  68. Text Justification

  Given an array of words and a width maxWidth, format the text such that
  each line has exactly maxWidth characters and is fully (left and right)
  justified.
 */

class Solution {
  void insertSpace( vector<string> words, int maxWidth, vector<string> &result,
		    bool last ) {
    if( last || words.size() == 1 ) {
      // for size=1, just one word, the left justify
      // for last line, add one space b/w each word
      string str = words[0];
      for( int j = 1; j < words.size(); ++j ) str += ' ' + words[j];
      str.append( maxWidth - str.size(), ' ' );
      result.push_back(str);   
    } else {
      int len = 0;
      for( auto word : words ) len += word.size();     
      // the first "mod" words get "div+1" spaces
      // the remaining words get "div" spaces
      int div = ( maxWidth - len ) / ( words.size() - 1 );
      int mod = ( maxWidth - len ) % ( words.size() - 1 );
      string str = words[0];
      for (int j = 1; j < words.size(); ++j) {
	if( j <= mod ) str.append( div+1, ' ' ); // one more space
	else str.append(div, ' ');
	str += words[j];
      }
      result.push_back( str );
    }
  }
    
public:
  vector<string> fullJustify( vector<string>& words, int maxWidth ) {
    int lineWidth = 0, i = 0;
    vector<string> line;
    vector<string> result;
    while( i < words.size() ) {
      if( lineWidth + words[i].size() <= maxWidth ) {
	line.push_back( words[i] );
	lineWidth += words[i].size() + 1;
	i++;
      } else {
	insertSpace( line, maxWidth, result, false );
	line.clear();
	lineWidth = 0;
      }
    }
    // last line
    if( line.size() > 0 ) insertSpace( line, maxWidth, result, true );
    return result;
  }
};
