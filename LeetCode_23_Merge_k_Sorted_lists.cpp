/*
  23. Merge k Sorted Lists
  Merge k sorted linked lists and return it as one sorted list.
  Analyze and describe its complexity.

  Example:
  Input:
  [
  1->4->5,
  1->3->4,
  2->6
  ]
  Output: 1->1->2->3->4->4->5->6
*/

struct NodeAndIndex {
  ListNode *node;
  int index;
  NodeAndIndex( ListNode* node, int index ) : node(node), index(index) {}
};

struct compareFn {
  bool operator() ( NodeAndIndex *n1, NodeAndIndex *n2 ) {
    return n1->node->val > n2->node->val;
  }
};

class Solution {
public:
  ListNode* mergeKLists( vector<ListNode*> &lists ) {
    if( lists.size() == 0 ) return nullptr;
        
    priority_queue< NodeAndIndex*, vector<NodeAndIndex*>, compareFn > minHeap;
    for( int i=0; i < lists.size(); i++ ) {
      if( lists[i] )
	minHeap.push( new NodeAndIndex( lists[i], i ) );
    }
        
    ListNode *head = new ListNode(0); // dummy head
    ListNode *curr = head;
    NodeAndIndex *tmp;
    while( !minHeap.empty() ) {
      tmp = minHeap.top();
      minHeap.pop();
      curr->next = tmp->node;
      curr = curr->next;
      if( curr->next ) {
	// means this link list has more elements
	minHeap.push( new NodeAndIndex( curr->next, tmp->index ) );
      } 
    }  
    return head->next;
  }
};
