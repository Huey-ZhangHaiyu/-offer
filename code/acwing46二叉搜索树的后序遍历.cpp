/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则返回true，否则返回false。
假设输入的数组的任意两个数字都互不相同。
*/
//二叉搜索树又称之为二叉排序树，它不为空树时，它中序遍历递增
//利用搜索树的性质，只用后序遍历即可还原树
class Solution {
public:
    vector<int> seq;
    bool verifySequenceOfBST(vector<int> sequence) {
        seq=sequence;
        return dfs(0,seq.size()-1);
    }
    
    bool dfs(int l,int r){
        if(l>=r) return true;
        int root=seq[r];
        int k=l;
        while(k<r&&seq[k]<root) k++;//数数左子树有多少个

        for(int i=k;i<r;i++){
            if(seq[i]<root) return false;//如果右子树中有比根小的数，非法
        }
        return dfs(l,k-1)&&dfs(k,r-1);
    }
};

//或者像acwing18题一样，利用排序可以知道中序遍历结果
//这道题就变成了已知中序遍历和后序遍历结果，重建二叉树
//我也不知道为什么这个代码不对。。
class Solution {
public:
    vector<int> inorder,postorder;
    unordered_map<int,int> pos;
    bool verifySequenceOfBST(vector<int> sequence) {
        postorder=sequence;
        inorder=sequence;
        sort(inorder.begin(),inorder.end());
        for(int i=0;i<inorder.size();i++){
            pos[inorder[i]]=i;
        }
        return dfs(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
    
    bool dfs(vector<int>&inorder, vector<int>&postorder,int il,int ir,int pl,int pr){
        if(il>=ir) return true;
        int root=postorder[pr];
        int k=pos[root];
        for(int i=pl;i<pl+(k-il);i++){
            if(postorder[i]>root) return false;
        }
        return dfs(inorder,postorder,il,il+k-1,pl,pl+(k-il)-1)&&dfs(inorder,postorder,il+k+1,ir,pl+(k-il),pr-1);
    }
};
