/*
  784. Letter Case Permutation
  Given a string S, we can transform every letter individually to be lowercase
  or uppercase to create another string.  Return a list of all possible strings we could create.

  Input: S = "a1b2"
  Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

  Input: S = "3z4"
  Output: ["3z4", "3Z4"]

  Input: S = "12345"
  Output: ["12345"]
 */

class Solution {
public:
  /**  
            a1b2   i=0, when it's at a, since it's a letter, we have two branches: a, A
         /        \
       a1b2       A1b2 i=1 when it's at 1, we only have 1 branch which is itself
        |          |   
       a1b2       A1b2 i=2 when it's at b, we have two branches: b, B
       /  \        / \
      a1b2 a1B2  A1b2 A1B2 i=3  when it's at 2, we only have one branch.
       |    |     |     |
      a1b2 a1B2  A1b2  A1B2 i=4 = S.length(). End recursion, add permutation to ans. 
      
      During this process, we are changing the S char array itself
  */
  vector<string> letterCasePermutation( string S ) {
    vector<string> result;
    backtrace( S, 0, result );
    return result;
  }
    
private:
  void backtrace( string S, int i, vector<string> &result ) {
    if( i == S.length() ) {
      result.push_back( S );
      return; 
    } 
    if( 'a' <= S[i] && S[i] <= 'z' ) { // two branches if a letter
      backtrace( S, i + 1, result );
      S[i] = 'A' + S[i] - 'a';
      backtrace( S, i + 1, result );
    } else if ( 'A' <= S[i] && S[i] <= 'Z' ) { // two branch if a letter 
      backtrace( S, i + 1, result );
      S[i] = 'a' + S[i] - 'A';
      backtrace( S, i + 1, result );
    } else { // one branch if a digit
      backtrace( S, i + 1, result );
    }
        
  }
};
