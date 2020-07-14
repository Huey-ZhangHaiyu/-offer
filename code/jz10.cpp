//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
//请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
//又他娘的是斐波那契，同jz07&jz08

class Solution {
public:
    int rectCover(int number) {
        return rectCover(number,1,2);
    }
private:
    int rectCover(int n, int a, int b){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return b;
        else return rectCover(n-1, b, a+b);
    }
};
