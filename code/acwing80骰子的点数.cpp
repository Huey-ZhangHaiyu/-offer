/*
将一个骰子投掷n次，获得的总点数为s，s的可能范围为n~6n。
请求出投掷n次，掷出n~6n点分别有多少种掷法。
样例
输入：n=2
输出：[1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1]
解释：投掷2次，可能出现的点数为2-12，共计11种。每种点数可能掷法数目分别为1,2,3,4,5,6,5,4,3,2,1。
所以输出[1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1]。
*/

/*
递归考虑的：指数级别的算法，会Timr Limit Exceed
1递归状态表示的是什么
2递归顺序是什么
dfs(n,s)递归状态就表示,扔n次，和为s的情况有多少种
每次假设扔了一次结果为i，那么递归变成i+dfs(n-1,s-i)
边界情况就是n减到了0或者s减到了负数，分别返回状态即可
*/
class Solution {
public:
    vector<int> numberOfDice(int n) {
        vector<int> res;
        for(int s=n;s<=6*n;s++){//结果是在n到6n之间
            res.push_back(dfs(n,s));//把每个可能的结果找出来
        }
        return res;
    }
    
    int dfs(int n,int s){
        if(n==0){//n减到最后为0
            if(s) return 0;//如果s没有刚好，那就完蛋
            if(!s) return 1;
        }
        if(s<0) return 0;//s减到小于0，完蛋
        int temp=0;
        for(int i=1;i<=6;i++){//每次确定一个可能的数字，去看看剩下的其他筛子的可能性
            temp+=dfs(n-1,s-i);
        }
        return temp;
    }
};

/*
动态规划：
状态表示f[i,j]表示前i次，总和是j的方案数
状态转移f[i,j]=f[i-1,j-1]+...+f[i-1,j-6];
*/
class Solution {
public:
    vector<int> numberOfDice(int n) {
        vector<vector<int>> f(n+1,vector<int>(6*n+1));
        f[0][0]=1;
        for(int i=1;i<=n;i++)//扔i次骰子的情况
            for(int j=1;j<=6*i;j++)//结果为j的情况
                for(int k=1;k<=6;k++)//投了一次k的情况
                    if(k<=j)//k最多到j
                        f[i][j]+=f[i-1][j-k];
        vector<int> res;
        for(int i=n;i<=6*n;i++)
            res.push_back(f[n][i]);
        return res;
    }
};

