//写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
/*
按位计算，0+0=0，0+1=1，1+1=0进位。所以相加的时候就是异或计算
计算进位，只有1+1会进位，所以做&运算并左移就是进位值
两者相加得到结果
*/
class Solution {
public:
    int Add(int num1, int num2)
    {
        int a=num1^num2;
        int b=(num1&num2)<<1;
        return a+b;//but这里用了+
    }
};

//改成递归，因为a+b就是调用Add函数
class Solution {
public:
    int Add(int num1, int num2)
    {
        int a=0;
        int b=0;
        if(num2!=0){
            a=num1^num2;
            b=(num1&num2)<<1;
            return Add(a,b);
        }
        return num1;//没有进位的时候，就终止
    }
};
