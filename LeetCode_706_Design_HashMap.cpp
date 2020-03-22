/*
  706. Design HashMap
 */

class MyHashMap {
  struct KV{ 
    int key, val;
    KV( int k, int v ) : key(k), val(v) {}
  };
  vector< list< KV* > > hash;
  size_t size = 10000;

  int getIndex( int key ) {
    return key % size;
  }
public:
  MyHashMap() {
    hash.resize( size );
  }
    
  void put( int key, int val ) {
    auto &list = hash[ getIndex(key) ];
    for (auto & kv : list ) {
      if( kv->key == key) {
	kv->val = val;
	return;
      }
    }
    list.emplace_back( new KV( key, val)  );
  }
    
  int get(int key) {
    const auto &list = hash[ getIndex( key ) ];
    if ( list.empty() )  return -1;
    for( const auto & kv : list ) {
      if( kv->key == key ) {
	return kv->val;
      }
    }
    return -1;
  }
    
  void remove(int key) {
    auto& list = hash[ getIndex( key ) ];
    for( auto it = list.begin(); it !=list.end(); it++ ) {
      if( (*it)->key == key ) { list.erase( it ); return; }
    }
  }
};
