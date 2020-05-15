/*
  House Robber III [LeetCode 337]
  The thief has found himself a new place for his thievery again. There is only one
  entrance to this area, called the "root." Besides the root, each house has one and
  only one parent house. After a tour, the smart thief realized that "all houses in this
  place form a binary tree". It will automatically contact the police if two directly-linked
  houses were broken into on the same night.

  Determine the maximum amount of money the thief can rob tonight without alerting the police.
*/

/* 
Input: [3,4,5,1,3,null,1]
input tree            dp tree:
     3                  [3+3+1,4+5]
    / \                /        \
   4   5            [4,3]      [5,1]
  / \   \          /     \          \
 1   2   1      [1,0]    [2,0]     [1,0]
                / \       /  \        /  \
           [0,0] [0,0] [0,0] [0,0]  [0,0] [0,0]

*/

pair<int,int> helper( TreeNode *node ) {
  if( !node ) return {0, 0};
  
  auto l = helper( node->left );
  auto r = helper( node->right );
  int withNode = node->val + l.second + r.second;
  int withoutNode = max( r.first, r.second ) + max( l.first, l.second ); 
  return { withNode, withoutNode };
}

int rob( TreeNode* root ) {
  auto res = helper( root );
  return max( res.first, res.second );
}
