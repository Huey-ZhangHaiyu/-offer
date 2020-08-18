/*
输入两个整数n和m，输出一个n行m列的矩阵，将数字 1 到 n*m 按照回字蛇形填充至矩阵中。

输入格式
输入共一行，包含两个整数n和m。

输出格式
输出满足要求的矩阵。

矩阵占n行，每行包含m个空格隔开的整数。

数据范围
1≤n,m≤100
输入样例：
3 3
输出样例：
1 2 3
8 9 4
7 6 5
*/

/*
想清楚思路：
碰壁条件：1.下一个位置已经走过 2.下一个位置出边界
所以循环每次把当前数字放进去后，先更新下一个位置并判断合理性
接着循环更新要填的数字
*/
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100+10; //养成多开几个的习惯，避免越界
int m, n;
int res[N][N];

int main() {
    cin >> n >> m;
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};//定义偏移量
    
    for(int i = 0, j = 0, num = 1, k = 0; num <= n * m; num ++){
        res[i][j] = num;
        
        int x = i + dx[k], y = j + dy[k];
        if(x < 0 || x >= n || y < 0 || y >= m || res[x][y]){
            k = (k + 1) % 4;//下一个偏移量
            x = i + dx[k], y = j + dy[k];
        }
        i = x, j = y;//更新位置
    }
    
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) cout << res[i][j] << " ";//输出
        cout<<endl;
    }
    
    return 0;
}
