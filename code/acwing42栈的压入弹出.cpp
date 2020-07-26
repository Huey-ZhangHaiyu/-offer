/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。

例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。

注意：若两个序列长度不等则视为并不是一个栈的压入、弹出序列。若两个序列都为空，则视为是一个栈的压入、弹出序列。
*/
//用一个栈去模拟就好了
//因为操作比较唯一
//当前压入与预计的输出相同，则当前元素必定要pop，如果不同则只能把下一个元素压进来
class Solution {
public:
    bool isPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size()!=popV.size()) return false;
        stack<int> stk;
        int i=0;
        for(auto x:pushV){//遍历整个输入
            stk.push(x);//模拟压入
            while(stk.size()&&stk.top()==popV[i]){//当压入的数和当前要弹出的数相同，说明这个数必须弹出
                stk.pop();//防止最后stk和popV都在这个while循环中空掉这一句pop就非法了
                i++;//等待弹出下一个
            }
        }
        return stk.empty();//如果stk完成了所有弹出，说明没问题
    }
};
