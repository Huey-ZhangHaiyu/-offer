/*
地上有一个 m 行和 n 列的方格，横纵坐标范围分别是 0∼m−1 和 0∼n−1。

一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格。

但是不能进入行坐标和列坐标的数位之和大于 k 的格子。

请问该机器人能够达到多少个格子？
*/

//DFS
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        vector<vector<bool>> vis(rows, vector<bool>(cols));
        return dfs(threshold, 0, 0, vis);
    }
    int dfs(int th, int i, int j, vector<vector<bool>> &vis){//参数传递的是形参，因此要在vis前面加个引用，表示这个数组的值已经修改
        if(i < 0 || i >=vis.size() || j < 0 || j >= vis[i].size() || vis[i][j] ||(i/10+i%10+j/10+j%10)>th) return 0;
        vis[i][j]=true;
        return dfs(th,i+1, j, vis)+dfs(th,i-1, j, vis)+dfs(th,i, j-1, vis)+dfs(th,i, j+1, vis) + 1;
    }
};
