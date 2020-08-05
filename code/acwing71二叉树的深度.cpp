//二叉树的定义就是递归生成的，所以一般二叉树问题用递归做
class Solution {
public:
    int treeDepth(TreeNode* root) {
        return dfs(root);
    }
    
    int dfs(TreeNode* root){
        if(!root) return 0;
        return max(dfs(root->left),dfs(root->right))+1;//深度就是左右子树深度的最大值加根1
    }
};
