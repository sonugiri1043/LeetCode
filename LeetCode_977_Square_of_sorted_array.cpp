vector<int> sortedSquares(vector<int>& A) {
  vector<int> posSq, negSq, result; // store +ve square, -ve square and final result
  for( auto a : A ) {
    if( a >= 0 ) posSq.push_back( a*a );
    else negSq.push_back( a*a );
  }
  // merge the +ve and -ve square using two pointer method
  // on -ve squares we iterate in reverse )
  int i=0, j=negSq.size() - 1;
  while( i < posSq.size() && j >= 0 ) {
    if( posSq[i] < negSq[j] ) {
      result.push_back( posSq[i] );
      i++;
    } else {
      result.push_back( negSq[j] );
      j--;
    }
  }
           
  while( i < posSq.size() ) {
    result.push_back( posSq[i] );
    i++;
  }
  while( j >= 0 ) {
    result.push_back( negSq[j] );
    j--;
  }        
  return result;
}
