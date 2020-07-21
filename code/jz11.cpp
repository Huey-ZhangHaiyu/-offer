//输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示。
//正常的时候，把n&1再右移就可以算出来
//但是n小于0的时候，n右移会补1，所以换成1左移就可以了
class Solution {
public:
     int  NumberOf1(int n) {
         int i=0;
         int flag=1;
         while(flag){//int类型一共32位，左移到31次时变成负数，左移第32次会溢出变0
              //C语言采用了丢弃最高位的处理方法,所以丢弃了1之后,i的值变成了0.
              //而如果直接t<<32，答案是1，是因为左移位数的mask是5位的，最大值就是31，大于31了就会对32取模，等于左移0，没变
             if(n&flag) i++;
             flag<<=1;//把1左移
         }
         return i;
     }
};
//强制转换成无符号类型
class Solution {
public:
    int NumberOf1(int n) {
        int res = 0;
        unsigned int un = n; 
        while (un) res += un & 1, un >>= 1;
        return res;
    }
};

//更巧妙的解法：
/*
如果一个整数不为0，那么这个整数至少有一位是1。如果我们把这个整数减1，
那么原来处在整数最右边的1就会变为0，原来在1后面的所有的0都会变成1，其余所有位将不会受到影响。
这个时候如果我们再把原来的整数和减去1之后的结果做与运算，从原来整数最右边一个1那一位开始所有位都会变成0
相当于扣除了最后一个1，用这种方法控制循环就行了
*/
class Solution {
    public: int NumberOf1(int n) {
        int count = 0;
        while(n!= 0){
            count++;
            n = n & (n - 1);
         }
        return count;
    }
};
