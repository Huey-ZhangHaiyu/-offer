/*
给出二叉树如下所示，并给出num=22。
      5
     / \
    4   6
   /   / \
  12  13  6
 /  \    / \
9    1  5   1

输出：[[5,4,12,1],[5,6,6,5]]
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> findPath(TreeNode* root, int sum) {
        dfs(root,sum);
        return res;
    }
    
    void dfs(TreeNode* root, int sum){
        if(!root) return;//遍历到NULL或者空树
        sum-=root->val;
        path.push_back(root->val);
        //当遍历到叶子，而且当前sum为0时
        if(!root->left&&!root->right&&!sum) return res.push_back(path);
        
        dfs(root->left,sum);
        dfs(root->right,sum);
        path.pop_back();//逐步恢复现场，要把当前子树走不通的点给一个一个pop出去
    }
};
