#include<iostream>
using namespace std;
const int N=1e6;
int a[N];

void merge_sort(int a[],int l,int r){
    if(l>=r) return;
    
    int mid=l+r>>1;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);
    
    int i=l,j=mid+1,k=0;
    int temp[r-l+1];
    while(i<=mid&&j<=r)
        if(a[i]<=a[j]) temp[k++]=a[i++];
        else temp[k++]=a[j++];
    while(i<=mid) temp[k++]=a[i++];
    while(j<=r) temp[k++]=a[j++];
    
    for(int i=l,j=0;i<=r;i++,j++) a[i]=temp[j];
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    merge_sort(a,0,n-1);
    for(int i=0; i<n; i++) printf("%d ", a[i]);
}
