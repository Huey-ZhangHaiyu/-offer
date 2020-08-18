/*请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。*/

//深度优先搜索
class Solution {
public:
    bool hasPath(vector<vector<char>>& matrix, string str) {
        for (int i = 0; i < matrix.size(); i ++ )
            for (int j = 0; j < matrix[i].size(); j ++ )//i，j为搜索头
                if (dfs(matrix, str, 0, i, j))//深度搜索有结果的话
                    return true;
        return false;
    }

    bool dfs(vector<vector<char>> &matrix, string &str, int u, int x, int y) {
        if (matrix[x][y] != str[u]) return false;//当前深度的值和字符串对应位置不同，此路径无效
        if (u == str.size() - 1) return true;//如果搜索深度为目标字符串的长度，则找到此字符串对应路径
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        char t = matrix[x][y];
        matrix[x][y] = '*';//遍历过的位置打星号
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];//向四个方向移动后的坐标
            if (a >= 0 && a < matrix.size() && b >= 0 && b < matrix[a].size()) {//限制边界
                if (dfs(matrix, str, u + 1, a, b)) return true;
            }
        }
        matrix[x][y] = t;//回溯，恢复现场
        return false;
    }
};
