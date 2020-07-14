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

//动态规划，避免纯递归的溢出
if(n<=1){
    return n;
}
int[] record = new int[n+2];
record[0] = 0;
record[1] = 1;
for(int i=2;i<=n;i++){
    record[i] = record[i-1] + record[i-2];
}
return record[n];
