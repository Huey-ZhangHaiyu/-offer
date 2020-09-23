//f[i, j]表示用j个鸡蛋测量i次能测量的区间长度的最大值
//枚举扔鸡蛋的楼层k，类似dp1，没碎测k楼以上，碎了测k楼以下，那么能测的最大高度就是上下两部分加上第k层楼这一层

#include <iostream>
using namespace std;

int f[110][15], n, m;

int main() {
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= m; j ++ )
                f[i][j] = f[i - 1][j] + f[i - 1][j - 1] + 1;//没碎+碎了+此层
            if (f[i][m] >= n) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
