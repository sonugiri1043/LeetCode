/**
 * Return the smallest character that is strictly larger than the search character,
 * If no such character exists, return the smallest character in the array
 * @param sortedStr : sorted list of letters, sorted in ascending order.
 * @param c : character for which we are searching.
 * Given the following inputs we expect the corresponding output:
 * ['c', 'f', 'j', 'p', 'v'], 'a' => 'c'
 * ['c', 'f', 'j', 'p', 'v'], 'c' => 'f'
 * ['c', 'f', 'j', 'p', 'v'], 'k' => 'p'
 * ['c', 'f', 'j', 'p', 'v'], 'z' => 'c' // The wrap around case
 * ['c', 'f', 'k'], 'f' => 'k'
 * ['c', 'f', 'k'], 'c' => 'f'
 * ['c', 'f', 'k'], 'd' => 'f'
 */

class Solution {
public:
  char nextGreatestLetter( vector<char>& letters, char target) {
    int n = letters.size();
    if( target < letters[0] || target >= letters[n-1] ) {
      return letters[0];
    }

    int start = 0, end = n-1;
    while( start <= end ) {
      int mid = (end+start)/2;
      if( letters[mid] == target ) {
	if( letters[mid+1] > target)
	  return letters[mid+1];
	else
	  start = mid + 1;
      } else if( target < letters[mid] )
	end = mid - 1;
      else // target > letters[mid]
	start = mid + 1;
    }
    return letters[start];
  }
};
