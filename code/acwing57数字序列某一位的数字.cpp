/*
数字以0123456789101112131415…的格式序列化到一个字符序列中。
在这个序列中，第5位（从0开始计数）是5，第13位是1，第19位是4，等等。
请写一个函数求任意位对应的数字。

样例
输入：13 输出：1
*/

/*
1位数有10个，2位数有90个，3位数有900个。。。
1.确定n是几位数：n-9*1-90*2-900*3---到不能减为止，假设为3位数
2.确定是3位数的第几个数：(n-9-90)/3-1=k;三位数中第k个数，即100+k
3.确定是三位数中的第几位：(n-9-90)%3=p;p=0最后一位,p=1第一位,p=2第二位
*/
class Solution {
public:
    int digitAtIndex(int n) {
        long long base=1,digit=1,s=9;//s为当前digit的数字个数
        
        if(n==0) return 0;
        
        //得到位数
        while(n-s*digit>0){
            n-=s*digit;
            digit++;
            s*=10;//不考虑0的情况比较好写
            base*=10;
        }
        //得到数字
        int number=base+(n+digit-1)/digit-1;//用向下取整代替向上取整[(n+d-1)/d]下取整=[n/d]上取整
        
        //得到数字的第几位
        int r=n%digit?n%digit:digit;
        for(int i=0;i<digit-r;i++){
            number/=10;
        }
        
        return number%10;
    }
};
