//请实现两个函数，分别用来序列化和反序列化二叉树。
//您需要确保二叉树可以序列化为字符串，并且可以将此字符串反序列化为原始树结构。

//注意是字符串噢
class Solution{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root){
        string res;
        dfs1(root, res);//先序遍历
        return res;
    }

    void dfs1(TreeNode* root, string& res){
        if (!root){
            res += "#,";
            return;
        }
        res += to_string(root->val) + ',';//int转字符
        dfs1(root->left, res);//左右都加进来
        dfs1(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int u = 0;
        return dfs2(data, u);
    }

    TreeNode* dfs2(string &data, int &u){
        if (data[u] == '#')
        {
            u += 2;//跳过#,
            return NULL;
        }

        int t = 0;
        bool is_minus = false;
        while (data[u] != ',')
        {
            if (data[u] == '-') is_minus = true;//数字为负
            else t = t * 10 + data[u] - '0';//字符转成整数
            u ++ ;
        }
        u ++ ;
        if (is_minus) t = -t;

        auto root = new TreeNode(t);
        root->left = dfs2(data, u);//先遍历的u一定是左子树
        root->right = dfs2(data, u);//后遍历的一定是右子树

        return root;
    }
};
