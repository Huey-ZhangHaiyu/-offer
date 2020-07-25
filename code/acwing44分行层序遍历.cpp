//从上到下按层打印二叉树，同一层的结点按从左到右的顺序打印，每一层打印到一行。
/*输入如下图所示二叉树[8, 12, 2, null, null, 6, null, 4, null, null, null]
    8
   / \
  12  2
     /
    6
   /
  4

输出：[[8], [12, 2], [6], [4]]
*/
//上一题的基础上改变，队列中的每一行最后加入null标识符
class Solution {
public:
    vector<vector<int>> printFromTopToBottom(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> level;
        if(!root) return res;
        
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
            else if(q.size()){//加条件防止只有最后一个null的时候
            //因为循环一开始null被pop出去了，此时数组长度为空，如果再不停的push进去null，则会死循环
                q.push(NULL);//数组里有null，长度不为零
                res.push_back(level);
                level.clear();
            }
        }
        return res;
    }
};
