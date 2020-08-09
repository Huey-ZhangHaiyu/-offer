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
//循环链表模拟
#include<list>
class Solution {
public:
    int lastRemaining(int n, int m){
        if (n<=0||m<=0) return -1;
	    list<int> list;
	    for(int i=0;i<n;i++)
		    list.push_back(i);
 
	    auto p=list.begin();
	    while (list.size()>1){
		    for (int i=1;i<m;i++){
			    p++;
			    if (p==list.end()) p=list.begin();
		    }
            p=list.erase(p);//erase返回下一个节点的位置
		    if (p == list.end()) p = list.begin();
    	}
    	return *(p);
    }
};

//递推公式，找到重新编号与旧编号之间的关系即可
//n个小朋友，报到m-1的人退出，那么0到(n-1)的小朋友第一个退出的一定是(m%n-1)号
//剩下0,1,...,(m%n-1)-1,(m%n-1)+1,...n-1;
//也就是.....,   k-1   ,    k    ,  ...;对应原序列
//替换成.....,   n-1   ,    0    ,1,...;新的序列   
//这就可以看成n-1个小朋友报数问题。
//假设最后剩下x号，那么找到x对应在原序列的位置就行了；
//在k到k-1中的x号在n个小朋友中的编号应该是x'=(x+k)%n;
//依次往下推下去，剩下n-2个小朋友时的序列里，最终的小朋友在n-1中的位置依旧满足x'=(x+k)%n;
//所以从最底层，也就是选出最后一个人开始倒推，最终剩下的人在i=1个人中编号一定为last=0；
//开始循环，从i=2层一直计算到n层
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n==0) return -1;
        int last=0;
        for(int i=2;i<=n;i++){
            last=(last+m)%i;
        }
        return last;
    }
};
