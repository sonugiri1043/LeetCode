/*
  Remove K Digits [LeetCode 402]
  Given a non-negative integer num represented as a string, remove k digits from the
  number so that the new number is the smallest possible.
  Note:
  The length of num is less than 10002 and will be ≥ k.
  The given num does not contain any leading zero.

  Example :
  Input: num = "1432219", k = 3
  Output: "1219"
  Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

  Input: num = "10200", k = 1
  Output: "200"
  Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
  
  Input: num = "10", k = 2
  Output: "0"
  Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

/*
  Let's think about the simplest case: how to remove 1 digit from the number so that the new
  number is the smallest possible？ Well, one can simply scan from left to right, and remove 
  the first "peak" digit; the peak digit is larger than its right neighbor. One can repeat
  this procedure k times, and obtain the first algorithm:

  Note, when the result stack (i.e. res) pop a digit, it is equivalent to removing that "peak" digit.
*/
string removeKdigits(string num, int k) {
  string res;
  int keep = num.size() - k;
  for( int i=0; i<num.size(); i++ ) {
    while( res.size()>0 && res.back() > num[i] && k>0 ) {
      res.pop_back();
      k--;
    }
    res.push_back(num[i]);
  }
  res.erase( keep, string::npos );
  
  // trim leading zeros
  int s = 0;
  while( s < (int)res.size()-1 && res[s]=='0' )  s++;
        
  res.erase( 0, s );
  return res=="" ? "0" : res;    
}
