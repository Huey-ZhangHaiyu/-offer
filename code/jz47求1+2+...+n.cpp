//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
//这题想考察的是什么？是程序短路！
//这才是正确答案，逻辑与有个短路特点，前面为假，后面不计算
class Solution {
public:
    int getSum(int n) {
        int ans=n;
        (n>0)&&(ans+=getSum(n-1));//用逻辑起到if的作用，核心还是递归做法
        return ans;
    }
};

//递归，用了if
class Solution {
public:
    int getSum(int n) {
        if(n<=0) return 0;
        return getSum(n-1)+n;
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
