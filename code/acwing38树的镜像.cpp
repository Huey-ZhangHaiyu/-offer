//输入一个二叉树，将它变换为它的镜像。

//一直套娃，套到最底层反转左右子树就好了
class Solution {
public:
    void mirror(TreeNode* root) {
        if(!root) return;
        mirror(root->left);
        mirror(root->right);
        swap(root->left,root->right);//交换两个指针
    }
};
