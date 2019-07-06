#include <iostream>

using std::cout;
using std::endl;

struct Node {
  int data;
  Node *next;

  Node( int data_ ) : data( data_), next( nullptr) {}
};

Node * createLL( int noOfNodes ) {
  if( noOfNodes <= 0 ) {
    return nullptr;
  }
  Node *node = new Node( 1 );
  Node *curr = node;
  for( int i=2; i <= noOfNodes; i++ ) {
    curr->next = new Node( i );
    curr = curr->next;
  }
  return node;
}

void printLinkList( Node *node ) {
  Node *curr = node;
  while( curr != nullptr ) {
    cout<< curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
}

void reverse( Node *head, int groupSize ) {
  Node *curr = head;
  Node *next = nullptr;
  Node *prev = nullptr;
  while( groupSize >= 0 && curr != nullptr ) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    groupSize--;
  }
}

Node *getTail( Node *node, int n ) {
  while( node->next != nullptr && n > 1 ) {
    node = node->next;
    n--;
  }
  return node;
}

Node* reverseLinkListInGroup( Node *node, int groupSize ) {
  Node *head = node;
  Node *tail = nullptr;
  Node *nextHead = nullptr;
  Node *prevHead = nullptr;
  Node *newHead = getTail( head, groupSize );

  while( head != nullptr ) {
    tail = getTail( head, groupSize );
    nextHead = tail ? tail->next : nullptr;
    reverse( head, groupSize-1 );
    if ( prevHead != nullptr ) {
      prevHead->next = tail;
    }
    prevHead = head; // new tail
    head = nextHead;
  }
  return newHead;
}

int main() {
  Node *head = createLL( 20 );
  printLinkList( head );
  Node *newHead = reverseLinkListInGroup( head, 3 );
  printLinkList( newHead );
  return 0;
}
