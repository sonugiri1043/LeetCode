class Solution {
public:
  string reverseWords(string s) {
    // step1: Reverse words one by one
    int start = 0, end = 0;
    bool word = false;
    for( int i = 0; i < s.length(); i++ ) {
      if( word && s[i] == ' ' ) {
	end = i;
	reverse( s.begin() + start, s.begin() + end);
	start = i+1;
	word = false;
      }
      else if( s[i] == ' ' ) {
	start = i + 1;
	word = false;
      } else {
	word = true;
	end = i;
      }
    }
    // Reverse the last word in string
    if(word) reverse(s.begin() + start, s.begin() + end + 1 );
        
    // step2: Reverse entire string
    reverse(s.begin(), s.end());
        
    // step3: Remove extra space
    int i = 0, j = 0;
    while( i < s.length() && s[i] == ' ') i++;
    bool space = false;
    while( i < s.length() ) {
      if( s[i] != ' ' ) { s[j++] = s[i++]; space = false; }
      else if( s[i] == ' ' && !space ) { space = true; s[j++] = s[i++]; }
      else if( space ) {i++;}
    }
    if( j>0 && s[j-1] == ' ') { --j;}
    return s.substr(0, j);
  }
};
