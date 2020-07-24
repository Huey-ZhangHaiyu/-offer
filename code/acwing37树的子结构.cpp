//输入两棵二叉树A，B，判断B是不是A的子结构。
//我们规定空树不是任何树的子结构。

//类似于数组当中做匹配，采用枚举根节点的办法
/*
代码分为两个部分：
遍历树A中的所有非空节点R；
判断树A中以R为根节点的子树是不是包含和树B一样的结构，且我们从根节点开始匹配；
*/
class Solution {
public:
    bool hasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {//这里实现了遍历树1的根节点
        if(!pRoot2||!pRoot1) return false;
        if(isPart(pRoot1,pRoot2)) return true;//如果当前根节点中包含树2的结构
        else return hasSubtree(pRoot1->left, pRoot2)||hasSubtree(pRoot1->right,pRoot2);//在树1的左右子树中继续找树2
    }
    
    bool isPart(TreeNode* pRoot1, TreeNode* pRoot2){//这里要同时遍历树1和2，看是不是拥有相同结构
        if(!pRoot2) return true;//把树2遍历完，说明有相同结构
        if(!pRoot1||pRoot1->val!=pRoot2->val) return false;//树1遍历完或者发现不同，失败
        else return isPart(pRoot1->left,pRoot2->left)&&isPart(pRoot1->right,pRoot2->right);//当前点不失败的同时，后续左右子树同时成功才能true
    }
};
