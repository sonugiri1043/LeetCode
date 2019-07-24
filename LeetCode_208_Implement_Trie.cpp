/*
  208. Implement Trie ( Prefix Tree )
  Implement a trie with insert, search, and startsWith methods.

  Example:
  Trie trie = new Trie();
  trie.insert("apple");
  trie.search("apple");   // returns true
  trie.search("app");     // returns false
  trie.startsWith("app"); // returns true
  trie.insert("app");   
  trie.search("app");     // returns true
  
  Note:
  You may assume that all inputs are consist of lowercase letters a-z.
  All inputs are guaranteed to be non-empty strings.
 */

class Trie {
  unordered_map<char, Trie*> children;
  bool wordEndHere;
public:
  Trie() {
    wordEndHere = false;
  }

  void insert( string word ) {
    Trie *curr = this;
    for( auto s : word ) {
      if( curr->children.find(s) == curr->children.end() ) {
	curr->children[s] = new Trie();
      }
      curr = curr->children[s];
    }
    curr->wordEndHere = true;
  }

  bool search( string word ) {
    Trie *curr = this;
    for( auto s : word ) {
      if( curr->children.find(s) == curr->children.end() ) {
	return false;
      }
      curr = curr->children[s];
    }
    return curr->wordEndHere;
  }
    
  bool startsWith( string prefix ) {
    Trie *curr = this;
    for( auto s : prefix ) {
      if( curr->children.find(s) == curr->children.end() ) {
	return false;
      }
      curr = curr->children[s];
    }
    return true;
  }
};
