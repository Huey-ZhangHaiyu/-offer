/*
给定一个浮点数n，求它的三次方根。

输入格式
共一行，包含一个浮点数n。

输出格式
共一行，包含一个浮点数，表示问题的解。

注意，结果保留6位小数。

数据范围
−10000≤n≤10000
输入样例：
1000.00
输出样例：
10.000000
*/
#include<iostream>
using namespace std;

double n;

double b_search(double n,double l, double r){
    while(r-l>1e-7){//精确到7位，才能保存正确的六位
        double mid=(l+r)/2;
        if(mid*mid*mid>n) r=mid;
        else l=mid;
    }
    return l;
}

int main(){
    cin>>n;
    double ans=b_search(n, -10000.0, 10000.0);
    printf("%.*f",6,ans);//保留6位小数
    
    return 0;
}
