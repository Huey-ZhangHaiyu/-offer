//斐波那契数列

//normal迭代
class Solution {
public:
    int Fibonacci(int n) {
        if(n<=0) return 0;
        if(n==1||n==2) return 1;
        int f1=1; 
        int f2=1;
        while(n > 2){
            f2+=f1;
            f1=f2-f1;
            n--;
        }
        return f2;
    }
};

//尾递归
/*
尾递归的本质，其实是将递归方法中的需要的“所有状态”通过方法的参数传入下一次调用中
尾递归的调用处于方法的最后，因此方法之前所积累下的各种状态对于递归调用结果已经没有任何意义，
因此完全可以把本次方法中留在堆栈中的数据完全清除，把空间让给最后的递归调用。
这样的优化1便使得递归不会在调用堆栈上产生堆积，意味着即时是“无限”递归也不会让堆栈溢出。
这便是尾递归的优势
*/
public class Solution {
    public int Fibonacci(int n) {
        return Fibonacci(n,0,1);
    }
          
    private static int Fibonacci(int n,int acc1,int acc2){
        if(n==0) return 0;
        if(n==1) return acc2;
        else     return Fibonacci(n - 1, acc2, acc1 + acc2);
         
    }
}
