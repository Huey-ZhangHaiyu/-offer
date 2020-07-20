//输入一棵二叉树前序遍历和中序遍历的结果，请重建该二叉树。
//二叉树中每个节点的值都互不相同；//利用这个可以构建哈希表
//输入的前序遍历和中序遍历一定合法；
/*
前序遍历的左边界第一个一定是根节点
在中序遍历中，根节点左边为左子树，右边为右子树，得到左子树数的个数，就可以推断出左右子树的边界范围
回到前序遍历即可知道对应子树的根节点，进行递归
*/
class Solution {
public:
    unordered_map<int,int> pos;//哈希表可以使得在中序遍历表中搜寻根节点的复杂度为O（1）
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            pos[inorder[i]]=i;//给中序遍历的数值定义哈希表
        }
        return dfs(preorder, inorder, 0, n-1, 0, n-1);//在树的边界内深度遍历
    }
    
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir){
        if(pl>pr) return NULL;//遍历到叶子之后一层返回NULL
        int k=pos[preorder[pl]]-il;//当前根节点的左子树数的个数
        TreeNode* root=new TreeNode(preorder[pl]);//当前根节点即为前序遍历的最左数
        root->left=dfs(preorder, inorder, pl+1, pl+k, il, il+k-1);//更新子树边界
        root->right=dfs(preorder, inorder, pl+k+1, pr, il+k+1, ir);//边界比较容易写错
        return root;
    }
};
