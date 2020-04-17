/*
  129. Sum Root to Leaf Numbers
  Given a binary tree containing digits from 0-9 only, each root-to-leaf path
  could represent a number.

  An example is the root-to-leaf path 1->2->3 which represents the number 123.
  Find the total sum of all root-to-leaf numbers.

  Note: A leaf is a node with no children.

  Input: [1,2,3]
    1
   / \
  2   3
  Output: 25

Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
 */

void dfs( TreeNode *node, int &path, int &sum ) {
  if( !node ) return;
  path = path*10 + node->val;
  if( !node->left && !node->right )
    sum += path;
  dfs( node->left, path, sum );
  dfs( node->right, path, sum );
  // backtrack
  path = path/10;
}
    
int sumNumbers( TreeNode* root ) {
  int sum=0, path=0;
  dfs( root, path, sum );
  return sum;
}
