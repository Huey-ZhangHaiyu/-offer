//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
//一个台阶1种，2个台阶2种
//n个台阶，就是第一次选择跳1级的情况f(n-1)加上第一次选择跳2级的情况f(n-2)
//即f(n)=f(n-1)+f(n-2)

class Solution {
public:
    int jumpFloor(int number) {
        return jumpFloor(number,1,2);
    }
private:
    int jumpFloor(int n, int a, int b){
        if(n==1) return 1;
        if(n==2) return b;
        else return jumpFloor(n-1, b, a+b);
    }
};
