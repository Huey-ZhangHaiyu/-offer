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
        vector<vector<bool>> vis(rows, vector<bool>(cols));//二维动态数组
        return dfs(threshold, 0, 0, vis);
    }
    int dfs(int th, int i, int j, vector<vector<bool>> &vis){//参数传递的是形参，因此要在vis前面加个引用，表示这个数组的值已经修改
        if(i < 0 || i >=vis.size() || j < 0 || j >= vis[i].size() || vis[i][j] ||(i/10+i%10+j/10+j%10)>th) return 0;//这里应该也要像下面那样写一个计算sum的函数才行
        vis[i][j]=true;
        return dfs(th,i+1, j, vis)+dfs(th,i-1, j, vis)+dfs(th,i, j-1, vis)+dfs(th,i, j+1, vis) + 1;
    }
};

//BFS比较好
//不断地将现在的点附近的点压入队列，再一个一个判断是否能到达，实现BFS
class Solution {
public:

    int get_sum(pair<int, int> p) {
        int s = 0;
        while (p.first) {
            s += p.first % 10;
            p.first /= 10;
        }
        while (p.second) {
            s += p.second % 10;
            p.second /= 10;
        }
        return s;
    }

    int movingCount(int threshold, int rows, int cols)
    {
        if (!rows || !cols) return 0;
        queue<pair<int,int>> q;//用一个队列储存点，用pair存储int对
        vector<vector<bool>> st(rows, vector<bool>(cols, false));//二维数组存储当前点是否能到达

        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

        int res = 0;//定义储存答案
        q.push({0, 0});//初始点压入栈
        while (q.size()) {
            auto t = q.front();
            q.pop();
            if (st[t.first][t.second] || get_sum(t) > threshold) continue;//已经寻找过或者数位之和大于threshold，直接去队列下一个点
            res ++ ;//计数+1
            st[t.first][t.second] = true;//这个位置能到达
            for (int i = 0; i < 4; i ++ ) {//周围的四个点
                int x = t.first + dx[i], y = t.second + dy[i];
                if (x >= 0 && x < rows && y >= 0 && y < cols) q.push({x, y});//可以就入栈待判断
            }
        }

        return res;
    }
};
