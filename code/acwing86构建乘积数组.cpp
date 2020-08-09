/*
给定一个数组A[0, 1, …, n-1]，请构建一个数组B[0, 1, …, n-1]，其中B中的元素B[i]=A[0]×A[1]×… ×A[i-1]×A[i+1]×…×A[n-1]。
不能使用除法。除了输出的数组之外只使用常数空间
*/
/*每个Bi就是把对应Ai删掉之后的其余数的乘积
难点在于常数空间和除法的限制
把步骤拆开做，先乘前一部分，再乘后一部分即可
*/
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n = A.size();
        vector<int> B(n,1);
        if(A.empty()) return vector<int>();

        for(int i=0;i<n;i++){
            for(int p=0;p<i;p++)
                B[i]*=A[p];
            for(int p=n-1;p>i;p--)
                B[i]*=A[p];
        }
        return B;
    }
};
