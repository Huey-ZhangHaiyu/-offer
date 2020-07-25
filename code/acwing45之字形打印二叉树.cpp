/*输入如下图所示二叉树[8, 12, 2, null, null, 6, 4, null, null, null, null]
    8
   / \
  12  2
     / \
    6   4
输出：[[8], [2, 12], [6, 4]]*/


class Solution {
public:
    vector<vector<int>> printFromTopToBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> level;
        bool flag=false;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(q.size()){
            auto t=q.front();
            q.pop();
            if(t){
                level.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            else if(q.size()&&!flag){
                q.push(NULL);
                res.push_back(level);
                level.clear();
                flag=true;
            }
            else if(q.size()&&flag){
                q.push(NULL);
                reverse(level.begin(),level.end());
                res.push_back(level);
                level.clear();
                flag=false;
            }
            
        }
        return res;
    }
};
