/*
  380. Insert Delete GetRandom O(1)

  Design a data structure that supports all following operations in average O(1) time.

  insert(val): Inserts an item val to the set if not already present.
  remove(val): Removes an item val from the set if present.
  getRandom: Returns a random element from current set of elements.
  Each element must have the same probability of being returned.
 */

class RandomizedSet {
  vector<int> arr; // stores actual data 
  unordered_map<int, int> dataToIndexMap; // maps data to it's index in array
public:
  RandomizedSet() { }

  bool insert( int val ) {
    if( dataToIndexMap.find( val ) == dataToIndexMap.end() ) {
      arr.push_back( val );
      dataToIndexMap[ val ] = arr.size() - 1;
      return true;
    }
    return false;
  }
    
  bool remove( int val ) {
    if( dataToIndexMap.find( val ) != dataToIndexMap.end() ) {
      arr[ dataToIndexMap[val] ] = INT_MIN;
      dataToIndexMap.erase( val );
      return true;
    }
    return false;
  }
    
  int getRandom() {
    int random =  arr[ rand() % arr.size() ];
    if( random != INT_MIN ) {
      return random;
    } else {
      return getRandom();
    }
  }
};
