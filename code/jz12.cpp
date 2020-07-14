//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
//注意base和exponent不能同时为0
//使用了一点快速幂方法
class Solution {
public:
    double Power(double base, int exponent) {
        double e=1.0; 
        int n=abs(exponent);
        if(base==0) return 0;
        if(exponent==0) return 1;
        while(n!=0){
            if((n&1)==1) e*=base;//&0001就可以把末尾位拿出来
            base*=base;// 翻倍
            n>>=1;// 右移一位
        }
        return exponent>=0?e:(1/e);
    }
};
