/*
输入一棵二叉树的根结点，判断该树是不是平衡二叉树。
如果某二叉树中任意结点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
*/
//在求得任意节点左右两边深度的时候判断一下就好
class Solution {
public:
    bool ans=true;//默认空树为true
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    int dfs(TreeNode* root){
        if(!root) return 0;//空节点返回0
        auto l=dfs(root->left);//左深度
        auto r=dfs(root->right);//右深度
        if(abs(l-r)>1) ans=false;//判断一下
        return max(l,r)+1;//返回此节点总深度
    }
};
