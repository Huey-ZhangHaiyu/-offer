//请用栈实现一个队列，支持如下四种操作：

//push(x) – 将元素x插到队尾；
//pop() – 将队首的元素弹出，并返回该元素；
//peek() – 返回队首元素；
//empty() – 返回队列是否为空；
/*
用两个栈实现队列的功能即可，考察功能理解
*/
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    stack<int> a,b;
    /** Push element x to the back of queue. */
    void push(int x) {
        a.push(x);
    }
    
    void copy(stack<int> &a,stack<int> &b){
        while(a.size()){
            b.push(a.top());
            a.pop();
        }
    }
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        copy(a,b);
        int ans=b.top();
        b.pop();
        copy(b,a);
        return ans;
    }
    
    /** Get the front element. */
    int peek() {
        copy(a,b);
        int ans=b.top();
        copy(b,a);
        return ans;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
