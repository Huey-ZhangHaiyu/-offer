/*
给出一个二叉树，输入两个树节点，求它们的最低公共祖先。
一个树节点的祖先节点包括它本身。

样例
二叉树[8, 12, 2, null, null, 6, 4, null, null, null, null]如下图所示：
    8
   / \
  12  2
     / \
    6   4

1. 如果输入的树节点为2和12，则输出的最低公共祖先为树节点8。
2. 如果输入的树节点为2和6，则输出的最低公共祖先为树节点2。
*/

/*
树的问题一定是递归来做的
    a
   / \
  b   c
如果要找的pq点都在b里面，那么去递归左子树b
如果pq分别在bc子树中，那么a就一定是公共祖先
如果a是pq其中一个或多个，那么a就是答案
*/
//函数本质是在寻找pq的位置，通过不同的位置去进行不同情况的判断
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;//空树或者叶子
        
        if(root==p||root==q) return root;//直接遍历到pq
        
        auto left=lowestCommonAncestor(root->left,p,q);//在左边找pq位置
        auto right=lowestCommonAncestor(root->right,p,q);
        
        if(left&&right) return root;//在两边
        else if(left) return left;//只有左边
        else return right;
    }
};
