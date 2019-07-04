#include <iostream>
#include <map>

struct Node {
  int data;
  Node *next, *random;
  Node( int data_ ) {
    data = data_;
    next = nullptr;
    random = nullptr;
  }
};

void print( Node *node ) {
  while( node != nullptr ) {
    std::cout<< "data: " << node->data << " next: " << node->next <<
      " random: " << node->random << std::endl;
    node = node->next;
  }
}

Node * cloneLinkList( Node *node ) {
  std::map< Node *, Node * > nodeMap;
  Node *curr = node;
  while( curr != nullptr ) {
    nodeMap.insert( std::make_pair( curr, new Node( curr->data ) ) );
    curr = curr->next;
  }
  nodeMap.insert( std::make_pair( nullptr, nullptr ) );

  // set the next and random pointer
  curr = node;
  while( curr != nullptr ) {
    nodeMap[ curr ]->next = nodeMap[ curr->next ];
    nodeMap[ curr ]->random = nodeMap[ curr->random ];
    curr = curr->next;
  }
  return nodeMap[ node ];
}

int main() {
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->random = head->next->next;

  print( head );
  print( cloneLinkList( head ) );
  return 0;
}
