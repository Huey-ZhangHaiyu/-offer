//从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。
//就是个宽搜
class Solution {
public:
    vector<int> printFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        while(q.size()){
            auto f=q.front();//f=root;
            res.push_back(f->val);
            q.pop();
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
        }
        return res;
    }
};
