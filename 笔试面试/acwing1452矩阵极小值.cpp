/*
给定一个 n×n 的矩阵，矩阵中包含 n×n 个 互不相同 的整数。

定义极小值：如果一个数的值比与它相邻的所有数字的值都小，则这个数值就被称为极小值。
一个数的相邻数字是指其上下左右四个方向相邻的四个数字，另外注意，处于边界或角落的数的相邻数字可能少于四个。
要求在 O(nlogn) 的时间复杂度之内找出任意一个极小值的位置，并输出它在第几行第几列。

本题中矩阵是隐藏的，你可以通过我们预设的 int 函数 query 来获得矩阵中某个位置的数值是多少。
例如，query(a,b) 即可获得矩阵中第 a 行第 b 列的位置的数值。

注意：
矩阵的行和列均从 0 开始编号。
query()函数的调用次数不能超过 (n+2)×⌈log2n⌉+n。
答案不唯一，输出任意一个极小值的位置即可。
数据范围
1≤n≤300，矩阵中的整数在int范围内。

输入样例：
[[1, 2, 3], [4, 5, 6], [7, 8, 9]]
输出样例：
[0, 0]
*/

/*
很难的题目。二分思想
*/
// Forward declaration of queryAPI.
// int query(int x, int y);
// return int means matrix[x][y].

class Solution {
public:
    vector<int> getMinimumValue(int n) {
        typedef long long LL;//因为数值最大为int，所以定义一个大于int的值，方便后面找极小值
        const LL INF=1e15;
        
        int l=0,r=n-1;
        while(l<r){
            int mid=l+r>>1;
            int k;
            LL val=INF;//如果val只是int的话，可能val直接比目标值大，没得找
            for(int i=0;i<n;i++){
                int t=query(i,mid);
                if(t<val){
                    val=t;
                    k=i;
                }
            }
            LL left=mid?query(k,mid-1):INF;
            LL right=mid+1<n?query(k,mid+1):INF;
            
            if(val<left&&val<right) return {k,mid};
            else if(left<val) r=mid-1;//更新lr
            else l=mid+1;
        }
        
        //最后剩的一列找一下极小值即可
        int k;
        LL val=INF;
        for(int i=0;i<n;i++){
            int t=query(i,r);//这时候的lr应该相等
            if(t<val){
                val=t;
                k=i;
            }
        }
        return {k,r};
    }
};
