#include <iostream>

using std::cout;
using std::endl;

struct Node {
  int data;
  Node *next;
  Node( int data ) : data( data ), next( NULL ) {}
};

std::pair<Node *, int>  multiplyLinkListWithSingleNumber( Node *node, int num  ) {
  std::pair< Node *, int > ret;
  Node *tmp  = new Node( 0 );
  if( node->next ) {
    ret = multiplyLinkListWithSingleNumber( node->next, num );
    tmp->next = ret.first;
    tmp->data += ret.second;
  }
  int mul = node->data * num + tmp->data;
  tmp->data = mul % 10;
  int carry = mul/10;
  return std::make_pair( tmp, carry );
}

Node * multiply( Node *node1, int num ) {
  std::pair< Node*, int> result;
  result = multiplyLinkListWithSingleNumber( node1, num );

  Node *output = result.first;
  if( result.second > 0 ) {
    Node *carry =  new Node( result.second );
    carry->next = output;
    output = carry;
  }
  return output;
}

Node *mergeTwoLL( Node *node1, Node *node2 ) {
  int len1 = 0;
  int len2 = 0;
  Node *tmp = node1;
  while( tmp != NULL ) {
    tmp = tmp->next;
    len1++;
  }

  tmp = node2;
  while( tmp != NULL ) {
    tmp = tmp->next;
    len2++;
  }
  // return a single linked-list                                                                                                                                                                                                                                                                                                                                                                                                       
}

Node *multiplyTwoLL( Node *node1, Node *node2 ) {
  Node *output;
  if( node2->next ) {
    output = multiplyTwoLL( node1, node2->next );
  }
  Node *output1;
  output1 = multiply( node1, node2->data );
  output = mergeTwoLL( output, output1 );
  return output;
}

int main() {
  // 789                                                                                                                                                                                                                                                                                                                                                                                                                               
  Node *head1 = new Node( 7 );
  head1->next = new Node( 8 );
  head1->next->next = new Node ( 9 );

  Node *head2 = new Node( 8 );
  head2->next = new Node( 7 );

  Node *tmp = multiply( head1, 8 );
  while( tmp != NULL ) {
    cout << tmp->data <<" ";
    tmp = tmp->next;
  }
  cout<< endl;
  return 0;
}
