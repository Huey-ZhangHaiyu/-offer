/*
设计一个支持push，pop，top等操作并且可以在O(1)时间内检索出最小元素的堆栈。

push(x)–将元素x插入栈中
pop()–移除栈顶元素
top()–得到栈顶元素
getMin()–得到栈中最小元素
*/

//用一个单调栈作为辅助栈

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk,min_stk;
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        //注意辅助栈为空的情况，而且有相同数字也要压入，所以为<=
        if(min_stk.empty()||x<=min_stk.top()) min_stk.push(x);
    }
    
    void pop() {
        if(min_stk.top()==stk.top()) min_stk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();    
    }
};
