/*
给定你一个长度为n的整数数列。
请你使用快速排序对这个数列按照从小到大进行排序。并将排好序的数列按顺序输出。

输入格式
输入共两行，第一行包含整数 n。
第二行包含 n 个整数（所有整数均在1~109范围内），表示整个数列。

输出格式
输出共一行，包含 n 个整数，表示排好序的数列。

数据范围
1≤n≤100000
*/
#include<iostream>
using namespace std;

const int N=1e6;
int a[N];

void quick_sort(int v[],int l, int r){
    if(l>=r) return;
    
    int i=l-1,j=r+1,mid=v[l+r>>1];
    while(i<j){
        do i++; while(v[i]<mid);
        do j--; while(v[j]>mid);
        if(i<j) swap(v[i],v[j]);
    }
    quick_sort(v,l,j);
    quick_sort(v,j+1,r);
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++) printf("%d ", a[i]);
    
    return 0;
}
