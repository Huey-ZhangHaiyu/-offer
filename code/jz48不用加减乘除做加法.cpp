//写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
/*
按位计算，不进位相加的时候就是^异或计算
计算进位，做&运算并左移就是进位值
两者相加得到结果
a+b=(a^b)+(a&b<<1)=(a^b)^(a&b<<1)+(a^b)&(a&b<<1)<<1=.....一直到没有进位，前一部分就是答案；
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
    int add(int num1, int num2){
        if(num2)
            return add(num1^num2,(num1&num2)<<1);
        return num1;//没有进位的时候，就终止
    }
};
