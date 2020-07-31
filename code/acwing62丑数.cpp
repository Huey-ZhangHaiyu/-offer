//质因子中不包含2.3.5以外的数称作丑数，找出第n个丑数

/*
思路的本质为三路归并
i=2,j=3,k=5
2*1,2*2,2*3,2*4,2*5,2*6,2*8,,,//没有2*7哈
3*1,3*2,3*3,3*4,3*5,3*6,3*8,,,
4*1,4*2,4*3,4*4,4*5,4*6,4*8,,,
每次找最小的插进来，并且记得1为第一个丑数
可以看到最后*的数组就是我们生成的数组
*/
class Solution {
public:
    int getUglyNumber(int n) {
        vector<int> v;
        v.push_back(1);//vector<int> v(1,1);
        int i=0,j=0,k=0;//全都先指向1
        while(v.size()<n){//while(--n)执行n-1次
            int t=min(v[i]*2,min(v[j]*3,v[k]*5));
            v.push_back(t);
            if(v[i]*2==t) i++;
            if(v[j]*3==t) j++;
            if(v[k]*5==t) k++;
        }
        return v.back();
    }
};
