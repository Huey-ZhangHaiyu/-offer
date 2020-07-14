//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
//这题想考察的是什么？是程序短路！
//这才是正确答案
public int Sum_Solution(int n) {
        int sum = n;
        boolean ans = (n>0)&&((sum+=Sum_Solution(n-1))>0);
        return sum;
    }
    
//循环
class Solution {
public:
    int Sum_Solution(int n) {
        int s=0;
        for(int i=0;i<=n;i++){
            s+=i;
        }
        return s;
    }
};

//递归？
class Solution {
public:
    int Sum_Solution(int n) {
        int s=n;
        if(n==0) return 0;
        if(n>0){
            s+=Sum_Solution(n-1);
        }
        return s;
    }
};

//尾递归
class Solution {
public:
    int Sum_Solution(int n) {
        return Sum_Solution(n,0);
    }
private:
    int Sum_Solution(int n, int s){
        if(n==0) return s;
        else if(n>0) return Sum_Solution(n-1,s+n);
    }
};
