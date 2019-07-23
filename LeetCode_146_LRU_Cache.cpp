/*
  146. LRU Cache
  Design and implement a data structure for Least Recently Used (LRU) cache.
  It should support the following operations: get and put.

  get(key) - Get the value (will always be positive) of the key if the key exists
  in the cache, otherwise return -1.

  put(key, value) - Set or insert the value if the key is not already present.
  When the cache reached its capacity, it should invalidate the least recently
  used item before inserting a new item.

  The cache is initialized with a positive capacity.

  Follow up:
  Could you do both operations in O(1) time complexity?

  Example:
  LRUCache cache = new LRUCache( 2 );

  cache.put(1, 1);
  cache.put(2, 2);
  cache.get(1);       // returns 1
  cache.put(3, 3);    // evicts key 2
  cache.get(2);       // returns -1 (not found)
  cache.put(4, 4);    // evicts key 1
  cache.get(1);       // returns -1 (not found)
  cache.get(3);       // returns 3
  cache.get(4);       // returns 4
 */

/* Use custom doubly linked list to get best performance */
class LRUCache {
  int maxCapacity;
  int currentCapacity;
  unordered_map< int, int > hashMap;
  list<int> deque;
public:
  LRUCache( int _capacity ) {
    maxCapacity = _capacity;
    currentCapacity = 0;
  }
    
  int get( int key ) {
    if( hashMap.find( key ) != hashMap.end() ) {
      deque.remove( key );
      deque.push_front( key );
      return hashMap[key];
    }
    return -1;
  }
    
  void put( int key, int value ) {
    if( hashMap.find( key ) != hashMap.end() ) {
      if( hashMap[key] != value ) {
	// value is not upto date
	hashMap[key] = value;
	deque.remove( key );
	deque.push_front( key );
      }
      return;
    }
    if( currentCapacity < maxCapacity ) {
      currentCapacity++;
    } else {
      hashMap.erase( deque.back() );
      deque.pop_back();
    }
    hashMap[ key ] = value;
    deque.push_front( key );
  }
};
