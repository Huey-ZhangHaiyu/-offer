/*
给定一棵二叉搜索树，请找出其中的第k小的结点。
*/
//搜索树中序遍历就是递增的，每次用k--记录一下就好
class Solution {
public:
    TreeNode* ans;
    TreeNode* kthNode(TreeNode* root, int k) {
        dfs(root,k);
        return ans;
    }
    
    void dfs(TreeNode* root, int &k){
        if(!root) return;
        dfs(root->left,k);//左
        
        k--;//每找一个节点减一次
        if(!k) ans=root;
        //k有可能小于0，如果k已经小于等于0了，就不用找右子树了
        else if(k>0) dfs(root->right,k);//右
    }
};
