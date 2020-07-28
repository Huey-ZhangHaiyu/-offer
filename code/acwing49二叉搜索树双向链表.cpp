//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表
//要求不能创建任何新的结点，只能调整树中结点指针的指向。
/*
搜索树的中序遍历就是一个排序链表
只需每次找到子树根的左右节点，然后把左->根，右->根即可
因为根本来就指向着左右，直接形成了一个双向表

 因为中序遍历的顺序是刚好对的：左中右
 那么在每次找到节点之后，把前一个节点链接到当前，把当前的左连接到上一个节点的后
 然后每次更新pre就好了
 当前为左子叶，那么左子叶的前为pre，NULL
 当前为父节点，会把左子叶的后接上父节点，父节点的前为pre，左子叶
 当前为右子叶，会把父节点的后接上右子叶，右子叶的前为pre，父节点
 当前为根，会把根的左接上前一个右子叶，前一个右子叶的后接上根
 以此类推
 */
class Solution {
public:

    TreeNode* pre = NULL;

    TreeNode* convert(TreeNode* root) {
        dfs(root);
        while(root && root->left) root = root->left;
        return root;
    }
    void dfs(TreeNode* root){//中序遍历变体
        if(!root) return;
        dfs(root->left);
        //把每一个节点的左连到上一个子树尾部
        root->left=pre;//当前点的左记为上一轮的节点
        if(pre) pre->right = root;//把当前节点接到上一轮的节点后面
        pre = root;//记录这一轮的节点

        dfs(root->right);
    }
};
