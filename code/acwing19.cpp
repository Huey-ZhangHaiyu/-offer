//给定一棵二叉树的其中一个节点，请找出中序遍历序列的下一个节点。
//如果给定的节点是中序遍历序列的最后一个，则返回空节点;
//二叉树一定不为空，且给定的节点一定不是空节点；

/*
//中序遍历，节点的右子树的最左边节点即为后继节点
//若此节点没有右子树且为其父的左子树，那它的后续节点即为父节点
//若此节点没有右子树且为其父的右子树，那它的后续节点即为爷爷节点
//上述两条合并，就是往上找到第一个自己为左子树的父节点
//若找不到说明此节点为中序遍历的最后一个点
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode *father;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* p) {
        if (p->right) {
            p = p->right;
            while (p->left) p = p->left;
            return p;
        }

        while (p->father && p == p->father->right) p = p->father;
        return p->father;
    }
};
