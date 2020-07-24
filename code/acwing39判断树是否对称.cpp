//请实现一个函数，用来判断一棵二叉树是不是对称的。
//如果一棵二叉树和它的镜像一样，那么它是对称的。

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return dfs(root->left,root->right);
        
    }
    bool dfs(TreeNode* p1, TreeNode* p2){
        if(!p1||!p2) return !p1&&!p2;//如果有节点为空，那么当两节点都为空时返回true
        if(p1->val!=p2->val) return false;
        return dfs(p1->left, p2->right)&&dfs(p1->right, p2->left);
    }
};
