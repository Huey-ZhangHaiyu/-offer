//首先,让小朋友们围成一个大圈。然后随机指定一个数m,让编号为0的小朋友开始报数。
//每次喊到m-1的那个小朋友要出列,并且不再回到圈中
//从他的下一个小朋友开始,继续0...m-1报数....直到剩下最后一个小朋友得到礼品
//(注：小朋友的编号是从0到n-1)
//如果没有小朋友，返回-1
//normal solution
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n==0) return -1;
        int array[n];
        int i = -1,step = 0, count = n;
        while(count>0){
            i++;
            if(i>=n) i=0;
            if(array[i] == -1) continue;
            step++;
            if(step==m) {
                array[i]=-1;
                step = 0;
                count--;
            }        
        }
        return i;
    }
};

//what!!?????
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n==0) return -1;
        int s=0;
        for(int i=2;i<=n;i++){
            s=(s+m)%i;
        }
        return s;
    }
};
